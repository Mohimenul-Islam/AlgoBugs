
ft = [1] * 400005
mod = 10 ** 9 + 7
for i in range(2, len(ft)):
    ft[i] = ft[i-1] * i % mod

def solve():
    n, m = [int(x) for x in input().split()]
    
    adj = [[] for x in range(n+1)]
    for i in range(m):
        u, v = [int(x) for x in input().split()]
        adj[u].append(v)
        adj[v].append(u)
    color = [-1] * (n+1)
    def dfs(u, c = 0):
        stacked = [u]
        while len(stacked) > 0:
            u = stacked.pop()
            for v in adj[u]:
                if color[v] == -1:
                    color[v] = 1 - color[u]
                    stacked.append(v)
                elif color[v] == color[u]:
                    return False

        return True
    
    
    cnt = [0] * (n+1)
    adj_cnt = [len(x) for x in adj]
    if dfs(1):
        for i in range(1, n+1):
            if len(adj[i]) == 1:
                cnt[adj[i][0]] += 1
                adj_cnt[adj[i][0]] -= 1
                adj_cnt[i] = 0
        
        ans = 1
        for i in range(1, n+1):
            ans = ans * ft[cnt[i]] % mod
                
        if max(adj_cnt) > 2:
            print(0)
            return
        if max(adj_cnt) == 2 and not (1 in adj_cnt):
            print(0)
            return
        if (1 in adj_cnt):
            print(ans * 4 % mod)
        else:
            print(ans * 2 % mod)
    else:
        print(0)
        

test = int(input())
for testcase in range(test):
    solve()