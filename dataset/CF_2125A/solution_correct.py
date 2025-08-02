for _ in range(int(input())):
    c = []
    for e in input():
        if e == 'T':
            print(e, end='')
        else:
            c.append(e)
    print(*c, sep='')