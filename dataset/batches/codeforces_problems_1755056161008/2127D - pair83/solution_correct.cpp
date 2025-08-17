#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    
    if (m != n - 1) {
        cout << 0 << endl;
        return;
    }

    if (n == 2) {
        cout << 2 << endl;
        return;
    }

    vector<int> fact(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        fact[i] = i * fact[i - 1] % MOD;
    }

    ll ans = 1, x = 0;
    for (int i = 0; i < n; i++) {
        int cnt1 = 0, cnt2 = 0;
        if (deg[i] > 1) 
            x++; 
        for (int j = 0; j < adj[i].size(); j++) {
            if (deg[i] > 1 && deg[adj[i][j]] == 1) {
                cnt1++;
            }
            if (deg[i] > 1 && deg[adj[i][j]] > 1) {
                cnt2++;
            }
        }   
        if (cnt2 > 2) {
            cout << 0 << endl;
            return;
        }
        ans = ans * fact[cnt1] % MOD;
    }
    ans = (x >= 2 ? ans * 4 % MOD : ans * 2 % MOD);
    cout << ans << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
