#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int N = 3 * 1e5 + 1;
vector<int> f(N);

int32_t main() {
    int tc; 
    cin >> tc;
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }

    while (tc--) {
        int n, m; 
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v; 
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }

        if (m >= n) { 
            cout << 0 << "\n"; 
            continue; 
        }

        int p = 0;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) continue;
            p++;
            int s = 0;
            for (int j = 0; j < adj[i].size(); j++)
                if (adj[adj[i][j]].size() == 1) s++;
            ans *= f[s];
            ans %= mod;
        }

        ans *= 2;
        ans %= mod;
        if (p >= 2) ans *= 2;
        ans %= mod;
        cout << ans << "\n";
    }
}