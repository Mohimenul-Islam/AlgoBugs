#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // Reusable buffers to avoid reallocations inside loop
        vector<int> b(n);
        vector<long long> pref(n + 1); // use long long as requested

        // Try values from n down to 1
        for (int v = n; v >= 1; --v) {
            // build transformed array b and prefix sums pref
            pref[0] = 0LL;
            for (int i = 0; i < n; ++i) {
                b[i] = (a[i] >= v) ? 1 : -1;
                pref[i + 1] = pref[i] + (long long)b[i];
            }

            // Maintain minimum prefix value among pref[0..right-k]
            long long min_pref = pref[0];
            int min_pos = 0;
            bool found = false;
            int out_l = -1, out_r = -1;

            // iterate right endpoint r from k..n (prefix index)
            for (int right = k; right <= n; ++right) {
                int idx = right - k;
                long long val = pref[idx];
                if (val < min_pref) {
                    min_pref = val;
                    min_pos = idx;
                }
                if (pref[right] - min_pref >= 0LL) {
                    // convert to 1-based
                    out_l = min_pos + 1;
                    out_r = right;
                    found = true;
                    break;
                }
            }

            if (found) {
                cout << v << " " << out_l << " " << out_r << '\n';
                break;
            }
        }
    }
    return 0;
}