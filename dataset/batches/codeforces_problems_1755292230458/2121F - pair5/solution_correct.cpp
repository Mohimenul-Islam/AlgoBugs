#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, s, x;
    cin >> n >> s >> x;

    map<ll, ll> cnt, cur;
    vector<ll> a(n + 1), prev(n + 1), prf(n + 1);
    for (int i = 1; i <= n; i++) { cin >> a[i]; }
    partial_sum(a.begin(), a.end(), prf.begin());

    ll res = 0;

    for (int i = 0; i <= n; i++) {
        if (a[i] > x) {
            cnt.clear(), cur.clear();
        } else if (a[i] == x) {
            for (int j = i; j >= 0; j--) {
                cnt[prf[j]] = cur[prf[j]];
                if (j < i and a[j] >= x) break;
            }
        }
        cur[prf[i]]++;
        res += cnt[prf[i] - s];
    }

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}

/*
 *
 */