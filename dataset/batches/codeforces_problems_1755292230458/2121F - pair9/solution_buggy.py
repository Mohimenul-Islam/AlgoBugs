import sys
from collections import defaultdict

def count_subarrays_with_sum(arr, target):
    freq = defaultdict(int)
    freq[0] = 1
    pre_sum = 0
    count = 0
    for num in arr:
        pre_sum += num
        count += freq.get(pre_sum - target, 0)
        freq[pre_sum] += 1
    return count

def main():
    data = sys.stdin.read().split()
    ptr = 0
    t = int(data[ptr])
    ptr += 1
    for _ in range(t):
        n = int(data[ptr])
        s = int(data[ptr+1])
        x = int(data[ptr+2])
        ptr += 3
        a = list(map(int, data[ptr:ptr+n]))
        ptr += n
        valid_segments = []
        current = []
        for num in a:
            if num > x:
                if current:
                    valid_segments.append(current)
                    current = []
            else:
                current.append(num)
        if current:
            valid_segments.append(current)
        ans = 0
        for seg in valid_segments:
            if not seg:
                continue
            T = count_subarrays_with_sum(seg, s)
            no_x_segs = []
            curr_no_x = []
            for num in seg:
                if num == x:
                    if curr_no_x:
                        no_x_segs.append(curr_no_x)
                        curr_no_x = []
                else:
                    curr_no_x.append(num)
            if curr_no_x:
                no_x_segs.append(curr_no_x)
            F = 0
            for subseg in no_x_segs:
                F += count_subarrays_with_sum(subseg, s)
            ans += (T - F)
        print(ans)

if __name__ == "__main__":
    main()
    