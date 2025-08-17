import sys
from collections import defaultdict

def solve():
    input = sys.stdin.read().split()
    ptr = 0
    t = int(input[ptr])
    ptr += 1
    for _ in range(t):
        n, s, x = map(int, input[ptr:ptr+3])
        ptr += 3
        a = list(map(int, input[ptr:ptr+n]))
        ptr += n
        
        if x not in a:
            print(0)
            continue
        
        # Find all positions where a[i] == x
        x_positions = [i for i in range(n) if a[i] == x]
        
        # Compute prefix sums
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + a[i]
        
        # Function to compute left and right boundaries
        def compute_boundaries():
            left = [-1] * n
            right = [n] * n
            stack = []
            
            # Left boundaries
            for i in range(n):
                while stack and a[stack[-1]] <= a[i]:
                    stack.pop()
                if stack:
                    left[i] = stack[-1]
                stack.append(i)
            
            stack = []
            # Right boundaries
            for i in range(n-1, -1, -1):
                while stack and a[stack[-1]] < a[i]:
                    stack.pop()
                if stack:
                    right[i] = stack[-1]
                stack.append(i)
            
            return left, right
        
        left_bound, right_bound = compute_boundaries()
        res = 0
        
        # Process each x position
        for i in x_positions:
            L = left_bound[i]
            R = right_bound[i]
            
            # The valid subarrays must include a[i] (which is x)
            # So l ranges from L+1 to i, and r ranges from i to R-1
            # We need to count prefix[r+1] - prefix[l] == s
            
            # We'll use a sliding window approach with frequency map
            freq = defaultdict(int)
            
            # Precompute prefix sums in (L, i]
            for l in range(L + 1, i + 1):
                val = prefix[l]
                freq[val] += 1
            
            # Query for each r in [i, R-1]
            for r in range(i, min(R, n)):
                target = prefix[r + 1] - s
                res += freq.get(target, 0)
        
        print(res)

solve()