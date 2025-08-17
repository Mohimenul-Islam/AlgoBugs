#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; ll s, x;
        cin >> n >> s >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll answer = 0;
        int i = 0;
        while (i < n) {
            if (a[i] > x) { ++i; continue; } // breaks any valid segment

            int j = i;
            while (j < n && a[j] <= x) ++j;
            int len = j - i; // block is a[i..j-1]

            // build prefix sums for this block: pref[0]=0, pref[k]=sum of first k elements of the block
            vector<ll> pref(len + 1, 0);
            for (int k = 1; k <= len; ++k) pref[k] = pref[k-1] + a[i + k - 1];

            // count all subarrays in the block with sum == s
            unordered_map<ll, ll> cnt;
            cnt.reserve((size_t)len * 2 + 10);
            cnt.max_load_factor(0.25);
            cnt[0] = 1;
            ll total_in_block = 0;
            for (int k = 1; k <= len; ++k) {
                ll cur = pref[k];
                auto it = cnt.find(cur - s);
                if (it != cnt.end()) total_in_block += it->second;
                cnt[cur] += 1;
            }

            // subtract subarrays that lie entirely in maximal segments with values < x (no element equal to x)
            ll subtract = 0;
            int pos = 1;
            while (pos <= len) {
                if (a[i + pos - 1] == x) { ++pos; continue; }
                int start = pos;
                while (pos <= len && a[i + pos - 1] < x) ++pos;
                int end = pos - 1;
                // count subarrays with sum s inside [start..end] using prefix sums
                cnt.clear();
                cnt.reserve((size_t)(end - start + 2) * 2 + 5);
                cnt.max_load_factor(0.25);
                // we want pairs (u,v) with start-1 <= u < v <= end and pref[v]-pref[u]=s
                // initialize with pref[start-1]
                cnt[pref[start - 1]] = 1;
                for (int idx = start; idx <= end; ++idx) {
                    ll cur = pref[idx];
                    auto it2 = cnt.find(cur - s);
                    if (it2 != cnt.end()) subtract += it2->second;
                    cnt[cur] += 1;
                }
            }

            answer += (total_in_block - subtract);
            i = j; // move to next block after j-1
        }

        cout << answer << '\n';
    }
    return 0;
}
