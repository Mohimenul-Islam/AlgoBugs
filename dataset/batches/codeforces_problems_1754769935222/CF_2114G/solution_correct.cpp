#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int op(int a, int b) {
    int base = a;
    while (base % 2 == 0 && base / 2 != b) base /= 2;
    if (base % 2 == 1) return a / base;
    int base2 = base;
    while (base2 % 2 == 0) base2 /= 2;
    return 1 + (a - base) / base2;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;

    // solve
    vector<ll> pref(n), suf(n);
    for (int i = 0; i < n-1; i++) {
        if (i > 0) pref[i] += pref[i-1];
        pref[i] += op(a[i], a[i+1]);
    }
    for (int i = n-1; i >= 1; i--) {
        if (i < n-1) suf[i] += suf[i+1];
        suf[i] += op(a[i], a[i-1]);
    }

    // ans
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll cur = 1 << __builtin_ctz(a[i]);
        if (i > 0) cur += pref[i-1];
        if (i < n-1) cur += suf[i+1];
        mx = max(mx, cur);
    }
    cout << ((n <= k && mx >= k) ? "YES\n" : "NO\n");
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}