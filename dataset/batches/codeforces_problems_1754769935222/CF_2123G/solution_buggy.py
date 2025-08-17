import math
import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    index = 1
    output_lines = []
    for _ in range(t):
        n = int(data[index])
        m = int(data[index+1])
        q = int(data[index+2])
        index += 3
        a = list(map(int, data[index:index+n]))
        index += n
        for _ in range(q):
            if data[index] == '1':
                index += 1
                pos = int(data[index]) - 1
                index += 1
                x = int(data[index])
                index += 1
                a[pos] = x
            else:
                index += 1
                k_val = int(data[index])
                index += 1
                if n == 0:
                    output_lines.append("YES")
                    continue
                g = math.gcd(k_val, m)
                residue_prev = a[0] % g
                bound0 = (m - 1 - residue_prev) // g
                if 0 > bound0:
                    output_lines.append("NO")
                    continue
                drop_count = 0
                valid = True
                for i in range(1, n):
                    residue_curr = a[i] % g
                    if residue_prev > residue_curr:
                        drop_count += 1
                    residue_prev = residue_curr
                    bound_curr = (m - 1 - residue_curr) // g
                    if drop_count > bound_curr:
                        output_lines.append("NO")
                        valid = False
                        break
                if valid:
                    output_lines.append("YES")
    sys.stdout.write("\n".join(output_lines))

if __name__ == "__main__":
    main()