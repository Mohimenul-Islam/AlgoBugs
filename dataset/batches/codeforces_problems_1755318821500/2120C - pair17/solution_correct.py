import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    out_lines = []
    for _ in range(t):
        n = int(data[index])
        m = int(data[index + 1])
        index += 2
        total_max = n * (n + 1) // 2
        if m < n or m > total_max:
            out_lines.append("-1")
        else:
            if m == n:
                out_lines.append("1")
                for i in range(2, n + 1):
                    out_lines.append(f"1 {i}")
            else:
                found = False
                r_found = None
                for r in range(n, 1, -1):
                    base_val = r + n - 1
                    if base_val > m:
                        continue
                    X = m - base_val
                    count_big = n - r
                    num_big = min(count_big, X // (r - 1)) if r > 1 else 0
                    rem = X - num_big * (r - 1)
                    if r - 2 < 0:
                        total_small_gain_available = 0
                    else:
                        total_small_gain_available = (r - 2) * (r - 1) // 2
                    if rem <= total_small_gain_available:
                        found = True
                        r_found = r
                        break
                if not found:
                    out_lines.append("-1")
                else:
                    r = r_found
                    if X == 0:
                        nodes = [i for i in range(1, n + 1) if i != r]
                        nodes.sort()
                        chain_order = [r] + nodes
                        out_lines.append(str(r))
                        for i in range(len(chain_order) - 1):
                            out_lines.append(f"{chain_order[i]} {chain_order[i + 1]}")
                    else:
                        moved_big = list(range(r + 1, r + 1 + num_big))
                        moved_small = []
                        current_rem = rem
                        for gain_val in range(r - 2, 0, -1):
                            if current_rem == 0:
                                break
                            if gain_val <= current_rem:
                                moved_small.append(gain_val + 1)
                                current_rem -= gain_val
                        moved_set = set(moved_big) | set(moved_small)
                        out_lines.append(str(r))
                        out_lines.append(f"{r} 1")
                        for i in range(2, n + 1):
                            if i == r:
                                continue
                            if i in moved_set:
                                continue
                            out_lines.append(f"1 {i}")
                        for node in moved_big:
                            out_lines.append(f"{r} {node}")
                        for node in moved_small:
                            out_lines.append(f"{r} {node}")
    sys.stdout.write("\n".join(out_lines) + "\n")

if __name__ == "__main__":
    main()
    