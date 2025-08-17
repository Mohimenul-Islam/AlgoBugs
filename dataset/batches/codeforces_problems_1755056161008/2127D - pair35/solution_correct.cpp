#include <bits/stdc++.h>
using namespace std;

#define SZ(x) int(x.size())

const int  MOD    = 1e9  + 7;
const int MXN    = 2e5  + 5;

int n, m, fact[MXN];
vector<int> adj[MXN];

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < MXN; i++) 
        fact[i] = (1ll * fact[i-1] * i) % MOD;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long ans = 2;
        int tl = 0;
        if (m >= n) ans = 0;
        for (int u = 1; u <= n; u++) {
            if (adj[u].size() > 1) {
                int x = 0;
                for (int v : adj[u]) {
                    x += (SZ(adj[v]) == 1);
                }
                if (x >= SZ(adj[u]) - 2) (ans *= fact[x]) %= MOD;
                else ans = 0;
            } else tl ++;
        }
        if (tl < n-1) tl = 2; else tl = 1;
        cout << (ans * tl % MOD) << '\n';
    }
    return 0;
}