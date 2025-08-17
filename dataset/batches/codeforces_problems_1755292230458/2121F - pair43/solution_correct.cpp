#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        int s, x;
        cin >> n >> s >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long ans = 0;
        int i = 0;
        while (i < n) {
            if (a[i] > x) { ++i; continue; }

            int L = i;
            while (i < n && a[i] <= x) ++i;
            int R = i - 1; 
            map<long long, int> cnt;
            long long pref = 0;
            cnt[0] = 1;
            for (int j = L; j <= R; ++j) {
                pref += a[j];
                long long need = pref - s;
                auto it = cnt.find(need);
                if (it != cnt.end()) ans += it->second;
                cnt[pref] += 1;
            }

            int j = L;
            while (j <= R) {
                if (a[j] == x) { ++j; continue; }
                int p = j;
                while (p <= R && a[p] < x) ++p; 
                map<long long, int> cnt2;
                long long pref2 = 0;
                cnt2[0] = 1;
                for (int k = j; k < p; ++k) {
                    pref2 += a[k];
                    long long need2 = pref2 - s;
                    auto it2 = cnt2.find(need2);
                    if (it2 != cnt2.end()) ans -= it2->second;
                    cnt2[pref2] += 1;
                }
                j = p;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
