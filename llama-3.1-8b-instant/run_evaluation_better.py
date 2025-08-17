import os
import sys
import json
import requests
import time
import glob

# --- LLM API Configuration ---

def get_api_config():
    """Return (endpoint, api_key, headers) from environment lazily."""
    endpoint = os.environ.get("LLM_API_ENDPOINT", "https://api.groq.com/openai/v1/chat/completions")
    api_key = os.environ.get("GROQ_API_KEY") or os.environ.get("OPENAI_API_KEY")
    headers = {"Authorization": f"Bearer {api_key}", "Content-Type": "application/json"} if api_key else None
    return endpoint, api_key, headers

# --- Script Configuration ---
WORKSPACE_ROOT = os.getcwd()
OUTPUT_FILENAME = "generated_test_case.txt"


def construct_prompt(problem_statement, bug_category, buggy_code):
    """
    Constructs a detailed prompt for the LLM to generate a failing test case.
    """
    return f"""You are an expert competitive programming tester. Your ONLY job is to generate ONE test case that will make this buggy code fail.

PROBLEM STATEMENT:
{problem_statement}

BUG TYPE: {bug_category}

BUGGY CODE:
{buggy_code}

CRITICAL REQUIREMENTS - FOLLOW EXACTLY:
1. Generate EXACTLY ONE test case (t=1)
2. STRICT FORMAT: 
   Line 1: 1
   Line 2: n s x (where 1≤n≤200000, -200000000000000≤s≤200000000000000, -1000000000≤x≤1000000000)  
   Line 3: exactly n space-separated integers (each between -1000000000 and 1000000000)

3. SMART SIZING: Use reasonable n values (like 5-50) unless the bug specifically requires large input

4. EXAMPLE FORMAT:
   1
   5 10 3
   1 2 3 2 2

5. NO CODE BLOCKS, NO ```bash, NO ```plaintext, NO explanations
6. JUST the raw numbers, nothing else
7. The test case should expose the bug based on the bug type provided

OUTPUT ONLY THE TEST CASE:"""


def call_llm(prompt):
    """
    Calls the specified LLM API with the given prompt.
    """
    endpoint, api_key, headers = get_api_config()
    if not api_key:
        print("  [Error] Missing API key. Set GROQ_API_KEY (or OPENAI_API_KEY). See .env.example.")
        return None

    data = {
        "model": "llama-3.1-8b-instant",
        "messages": [{"role": "user", "content": prompt}],
        "temperature": 0.1,
        "max_tokens": 4000,  # Much higher to accommodate large arrays
    }

    try:
        response = requests.post(endpoint, headers=headers, json=data, timeout=120)
        response.raise_for_status()
        
        response_json = response.json()
        test_case = response_json['choices'][0]['message']['content'].strip()
        
        # Clean up the response - remove code blocks and extra formatting
        lines = test_case.split('\n')
        clean_lines = []
        
        for line in lines:
            line = line.strip()
            # Skip empty lines and markdown formatting
            if not line or line.startswith('```') or line.startswith('TEST CASE:'):
                continue
            # Only keep lines that look like actual test input (contain numbers or are simple)
            if line and (any(char.isdigit() or char == '-' for char in line)):
                clean_lines.append(line)
        
        return '\n'.join(clean_lines[:3])  # Only take first 3 lines (t, n s x, array)
        
    except requests.exceptions.RequestException as e:
        print(f"  [Error] API call failed: {e}")
        return None
    except (KeyError, IndexError) as e:
        print(f"  [Error] Could not parse LLM response: {e}")
        return None


def process_pair_directory(dir_path):
    """
    Processes a single pairXX directory.
    """
    print(f"- Processing '{os.path.basename(dir_path)}'...")
    
    output_path = os.path.join(dir_path, OUTPUT_FILENAME)
    if os.path.exists(output_path):
        print("  [Skipped] Test case already exists.")
        return True

    try:
        with open(os.path.join(dir_path, 'metadata.json'), 'r') as f:
            metadata = json.load(f)
        
        bug_category = metadata.get("bug_category")
        buggy_solution_file = metadata.get("buggy_solution_file")

        if not bug_category or not buggy_solution_file:
            print("  [Error] 'bug_category' or 'buggy_solution_file' not found in metadata.json.")
            return False

        with open(os.path.join(dir_path, 'problem_statement.md'), 'r') as f:
            problem_statement = f.read()

        with open(os.path.join(dir_path, buggy_solution_file), 'r') as f:
            buggy_code = f.read()

        prompt = construct_prompt(problem_statement, bug_category, buggy_code)
        print("  [Info] Calling LLM API to generate test case...")
        
        # Retry logic for rate limiting
        max_retries = 3
        for attempt in range(max_retries):
            generated_test_case = call_llm(prompt)
            
            if generated_test_case:
                # Validate the format before saving
                lines = generated_test_case.strip().split('\n')
                if len(lines) >= 3 and lines[0].strip() == '1':
                    with open(output_path, 'w') as f:
                        f.write(generated_test_case)
                    print(f"  [Success] Saved generated test case")
                    return True
                else:
                    print(f"  [Warning] Invalid format generated, retrying...")
            
            if attempt < max_retries - 1:
                wait_time = (2 ** attempt) * 5
                print(f"  [Retry {attempt + 1}] Waiting {wait_time}s before retry...")
                time.sleep(wait_time)
            else:
                print("  [Failed] Could not generate valid test case after retries.")
                return False

    except FileNotFoundError as e:
        print(f"  [Error] Missing file in directory: {e}")
        return False
    except Exception as e:
        print(f"  [Error] An unexpected error occurred: {e}")
        return False


def main():
    """
    Main function to find and process all pair directories.
    """
    search_pattern = os.path.join(WORKSPACE_ROOT, "2121F - pair*")
    pair_directories = sorted(glob.glob(search_pattern))

    if not pair_directories:
        print(f"Error: No '2121F - pair*' directories found in '{WORKSPACE_ROOT}'.")
        return

    print(f"Found {len(pair_directories)} pair directories to process.")
    
    completed = 0
    failed = 0
    
    for dir_path in pair_directories:
        if os.path.isdir(dir_path):
            success = process_pair_directory(dir_path)
            if success:
                completed += 1
            else:
                failed += 1
            
            # Conservative rate limiting
            time.sleep(3)
    
    print(f"\nEvaluation finished: {completed} completed, {failed} failed")


if __name__ == "__main__":
    main()
