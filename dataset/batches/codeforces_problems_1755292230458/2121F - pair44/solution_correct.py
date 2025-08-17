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
        nums = list(map(int, input[ptr:ptr+n]))
        ptr += n
        
        prefix = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix[i] = prefix[i - 1] + nums[i - 1]
        
        ans = 0
        dic = defaultdict(int)
        left = 0
        
        for r in range(n):
            if nums[r] > x:
                dic = defaultdict(int) 
                left = r + 1
            elif nums[r] == x:
                for l in range(left, r + 1):
                    dic[prefix[l]] += 1
                left = r + 1
            ans += dic.get(prefix[r + 1] - s, 0)
        
        print(ans)

solve()