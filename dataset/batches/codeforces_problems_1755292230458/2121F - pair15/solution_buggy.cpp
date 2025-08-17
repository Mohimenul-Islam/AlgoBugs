#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count_subarrays_with_sum(const vector<ll>& a, int L, int R, ll target) {
    // count number of subarrays in a[L..R-1] with sum == target
    unordered_map<ll, ll> cnt;
    cnt.reserve((R - L) * 2 + 10);
    cnt.max_load_factor(0.7);
    ll cur = 0;
    cnt[0] = 1;
    ll ans = 0;
    for (int i = L; i < R; ++i) {
        cur += a[i];
        auto it = cnt.find(cur - target);
        if (it != cnt.end()) ans += it->second;
        cnt[cur] += 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        ll s, x;
        cin >> n >> s >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll answer = 0;
        int i = 0;
        while (i < n) {
            if (a[i] > x) { ++i; continue; } // breaks blocks
            int j = i;
            while (j < n && a[j] <= x) ++j; // block [i, j)
            // total subarrays in this block with sum == s
            ll total_in_block = count_subarrays_with_sum(a, i, j, s);

            // count subarrays with sum == s that contain NO element == x
            ll total_without_x = 0;
            int p = i;
            while (p < j) {
                if (a[p] == x) { ++p; continue; }
                int q = p;
                while (q < j && a[q] < x) ++q;
                total_without_x += count_subarrays_with_sum(a, p, q, s);
                p = q;
            }

            answer += (total_in_block - total_without_x);
            i = j;
        }

        cout << answer << '\n';
    }
    return 0;
}
