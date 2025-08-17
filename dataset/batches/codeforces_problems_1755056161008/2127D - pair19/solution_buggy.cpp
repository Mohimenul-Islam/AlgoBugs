#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll d[200500];
ll md = (ll)1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (m >= n) {
        cout << 0;
        return;
    } 
    vector<ll> cnt(n + 1);
    ll f = 1;
    for (int i = 1; i <= n; ++i) {
        for (int to : g[i]) {
            if (g[to].size() == 1) {
                cnt[i]++;
            }
            if (g[i].size() > 1 && g[to].size() > 1) {
                f = 2;
            }
        }
    }
    ll ans = 1, cn = 0;
    for (int i = 1; i <= n; ++i) {
        ans *= d[cnt[i]];
        ans %= md;
    }
    ans *= (ll)2;
    ans *= f;
    ans %= md;
    cout << ans;
}

signed main() {
    //freopen("C:/Users/Dinislam/olimp/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    d[1] = 1;
    d[0] = 1;
    for (ll i = 2; i <= 200001; ++i) {
        d[i] = d[i - 1] * (ll)i;
        d[i] %= md;
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}
