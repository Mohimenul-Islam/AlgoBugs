#include<bits/stdc++.h>

using namespace std;

using i64 = long long;
typedef pair<i64, i64> pii;
const i64 mod = 1e9+7;
const i64 N = 2e5+5;

i64 fact[N];

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>> e(n);
    for (int i = 0; i < m; i++) {
        i64 u, v;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (m != n-1) {
        cout << "0\n";
        return;
    }
    if (n == 2){
        cout << "2\n";
        return;
    }
    i64 ans = 4;
    for (int i = 0; i < n; i++) {
        if (e[i].size() > 1) {
            i64 cnt = 0;
            for (auto x : e[i]) {
                if (e[x].size() != 1) {
                    cnt++;
                }
            }
            if (cnt > 2) {
                cout << "0\n";
                return;
            }
            if (cnt == 0) ans /= 2;
            ans = ans * fact[e[i].size()-cnt] % mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = i*fact[i-1]%mod;
    }
    while (t--) {
        solve();
    }
    return 0;
}