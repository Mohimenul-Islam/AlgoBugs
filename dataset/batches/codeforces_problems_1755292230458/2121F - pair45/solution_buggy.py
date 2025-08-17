import sys
from collections import defaultdict

def main():
    input = sys.stdin.read().split()
    ptr = 0
    t = int(input[ptr])
    ptr += 1
    results = []
    
    for _ in range(t):
        n = int(input[ptr])
        s = int(input[ptr+1])
        x = int(input[ptr+2])
        ptr += 3
        a = list(map(int, input[ptr:ptr+n]))
        ptr += n
        
        count = 0

        for l in range(n):
            current_sum = 0
            current_max = -float('inf')
            for r in range(l, n):
                current_sum += a[r]
                if a[r] > current_max:
                    current_max = a[r]
 
                if current_max > x:
                    break
                
                if current_sum == s and current_max == x:
                    count += 1
        
        results.append(str(count))
    
    print('\n'.join(results))

if __name__ == "__main__":
    main()