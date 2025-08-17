#include <bits/stdc++.h>
using ll = int64_t;
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
vector<int> fac(N);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (m != n - 1) {
        cout << 0 << '\n';
        return;
    }
    if (m == 1) {
        cout << 2 << '\n';
        return;
    }
    int d = 0;
    vector<int> val(n);
    auto dfs = [&](this auto &&self, int x, int fa) ->int {
        int mx = 0;
        if (adj[x].size() == 1 && fa != -1) {
            val[fa]++;
        }
        for (auto y : adj[x]) {
            if (y == fa) continue;
            int t = self(y, x);
            d = max(d, t + 1 + mx);
            mx = max(t, mx);
        }
        return mx + 1;
    };
    dfs(0, -1);
    if (adj[0].size() == 1) {
        val[adj[0][0]]++;
    }
    ll ans = 2;
    if (d > 3) {
        ans = 4;
    }
    for (int i = 0; i < n; i++) {
        if (val[i]) {
            d += val[i];
            ans = 1ll * ans * fac[val[i]] % mod;
        }
    }
    if (d != n + 2) {
        ans = 0;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    int tt = 1; cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}