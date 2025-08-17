#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#define all(v) v.begin(), v.end()

template<class T>
void chmax(T& a, T b) {
    a = a > b ? a : b;
}

template<class T>
void chmin(T& a, T b) {
    a = a < b ? a : b;
}

mt19937_64 mt_rng(random_device{}());

ll rng(ll l, ll r) {
    return mt_rng() % (r - l + 1) + l;
}

void solve() {
    int n;
    cin >> n;
    
    ll s;
    int x;
    cin >> s >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> prex(n + 1);
    for (int i = 0; i < n; i++) {
        prex[i + 1] = prex[i] + (a[i] == x);
    }
    
    auto calc = [&](int l, int r) {
        ll res = 0, sum = 0;
        map<ll, vector<int>> ma;
        ma[0].push_back(0);
        for (int i = l; i < r; i++) {
            int p = lower_bound(all(prex), prex[i + 1]) - prex.begin() - 1;
            sum += a[i];
            ma[sum].push_back(i + 1);
            if (p >= l && ma.count(sum - s)) {
                int pos = upper_bound(all(ma[sum - s]), p) - ma[sum - s].begin();
                res += pos;
            }
        }
        return res;
    };
    
    ll ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            ans += calc(l, i);
            l = i + 1;
        }
    }
    ans += calc(l, n);
    cout << ans << '\n';
}

int main() {
    // freopen("D.in", "r", stdin);
    // freopen("D.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}