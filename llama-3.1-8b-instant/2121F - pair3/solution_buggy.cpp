#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, s, x;
    cin >> n >> s >> x;

    vector<long long> v(n + 1), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = pref[i - 1] + v[i];
    }

    long long ans = 0;
    unordered_map<long long, int> cnt;
    cnt.reserve(n * 2);
    int lef = 1; // first index not yet inserted into cnt

    for (int r = 1; r <= n; r++) {
        if (v[r] > x) {
            cnt.clear();
            lef = r + 1;
        }
        else if (v[r] == x) {
            while (lef <= r) {
                cnt[pref[lef - 1]]++;
                lef++;
            }
        }
        if (!cnt.empty()) {
            ans += cnt[pref[r] - s];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
