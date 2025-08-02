#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int tcnt = 0;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;

    // solve
    vector<int> p2(n, 1), b(a);
    for (int i = 0; i < n; i++) {
        while (b[i] % 2 == 0) p2[i] *= 2, b[i] >>= 1;
    }
    vector<ll> pref(n), suf(n);
    for (int i = 0; i < n-1; i++) {
        if (i > 0) pref[i] += pref[i-1];
        pref[i] += p2[i];
        pref[i] -= (b[i] == a[i+1]);
    }
    for (int i = n-1; i >= 1; i--) {
        if (i < n-1) suf[i] += suf[i+1];
        suf[i] += p2[i];
        suf[i] -= (b[i] == a[i-1]);
    }

    // ans
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll cur = p2[i];
        if (i > 0) cur += pref[i-1];
        if (i < n-1) cur += suf[i+1];
        mx = max(mx, cur);
    }
    cout << ((n <= k && mx >= k) ? "YES\n" : "NO\n");

    // why would i say yes when ans is no
    // mx is too high
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) ++tcnt, solve();
}