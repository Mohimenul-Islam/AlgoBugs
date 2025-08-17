import sys

def main():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx])
    idx += 1
    for _ in range(t):
        n = int(input[idx])
        m = int(input[idx+1])
        idx +=2
        if m < n or m > n * n:
            print(-1)
            continue
        lower_r = (m + n - 1) // n  # ceil(m/n)
        upper_r = m - (n-1)
        if upper_r > n:
            upper_r = n
        if lower_r > upper_r or lower_r <1 or upper_r >n:
            print(-1)
            continue
        found = False
        chosen_r = -1
        chosen_k = -1
        for r in range(lower_r, upper_r +1):
            if r == 1:
                if m == n:
                    chosen_r = r
                    chosen_k = 0
                    found = True
                    break
                else:
                    continue
            S_low_r = (r*r - r + 2 * n) // 2
            if S_low_r > m:
                continue
            needed = m - S_low_r
            if (needed % (r-1)) != 0:
                continue
            k = needed // (r-1)
            if k <0 or k > (n - r):
                continue
            chosen_r = r
            chosen_k = k
            found = True
            break
        if not found:
            print(-1)
            continue
        root = chosen_r
        print(root)
        # edge between root and 1
        print(root, 1)
        # connect nodes less than root to 1
        for v in range(2, root):
            print(1, v)
        # nodes >= root+1
        nodes_ge = []
        for v in range(root +1, n+1):
            nodes_ge.append(v)
        k_val = chosen_k
        for i in range(len(nodes_ge)):
            v = nodes_ge[i]
            if i < k_val:
                print(root, v)
            else:
                print(1, v)

if __name__ == "__main__":
    main()
    