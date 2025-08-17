from collections import defaultdict

def solve(nums, s, x):
    n = len(nums)
    prefix = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix[i] = prefix[i - 1] + nums[i - 1]

    ans = 0
    dic = defaultdict(int)
    left = 0

    for r in range(n):
        if nums[r] > x:
            dic.clear()
            left = r + 1
        elif nums[r] == x:
            for l in range(left, r + 1):
                dic[prefix[l]] += 1
            left = r + 1
        ans += dic[prefix[r + 1] - s]

    print(ans)

t = int(input())
for _ in range(t):
    n, s, x = map(int, input().split())
    nums = list(map(int, input().split()))
    solve(nums, s, x)
