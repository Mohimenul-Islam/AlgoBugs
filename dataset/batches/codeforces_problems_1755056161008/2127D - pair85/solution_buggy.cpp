#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << "=" << x << '\n';
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a));
#define int long long
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
vector<int> fac(N);

void ini() {
    fac[1] = 1;
    for (int i = 2; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    if (m != n - 1) {
        cout << 0 << endl;
        return;
    }
    int ans = 2;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].size() > 1) {
            int x = 0;
            for (int v : a[i]) {
                x += (a[v].size() == 1);
            }
            if (x >= a[i].size() - 2) ans = (ans * fac[x]) % mod;
            else {
                cout << 0 << endl;
                return;
            }
        }
        else t++;
    }
    if (t < n - 1) ans = (ans * 2) % mod;
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ini();
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}