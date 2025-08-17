#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// count subarrays with sum = s and max <= K
static long long count_leq(const vector<long long>& a, long long s, long long K) {
    const int n = (int)a.size();
    long long total = 0;

    int l = 0;
    while (l < n) {
        // skip elements > K (they break segments)
        if (a[l] > K) { ++l; continue; }
        int r = l;
        while (r < n && a[r] <= K) ++r; // [l, r)

        int m = r - l;
        // prefix sums on this segment
        vector<long long> ps(m + 1, 0);
        for (int i = 0; i < m; ++i) ps[i + 1] = ps[i] + a[l + i];

        // coordinate compression of {ps[i]} ∪ {ps[i]-s}
        vector<long long> vals; vals.reserve(2 * (m + 1));
        for (int i = 0; i <= m; ++i) {
            vals.push_back(ps[i]);
            vals.push_back(ps[i] - s);
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto idx = [&](long long x) -> int {
            return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
        };

        vector<long long> cnt(vals.size(), 0);
        long long ans = 0;
        for (int i = 0; i <= m; ++i) {
            ans += cnt[idx(ps[i] - s)];
            cnt[idx(ps[i])]++;
        }
        total += ans;

        l = r; // next segment
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; long long s, x;
        cin >> n >> s >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long ans = count_leq(a, s, x) - count_leq(a, s, x - 1);
        cout << ans << '\n';
    }
return 0;
}
