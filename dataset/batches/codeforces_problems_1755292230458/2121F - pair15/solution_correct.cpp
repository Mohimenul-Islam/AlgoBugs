#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// splitmix64 for faster and safer hashing
struct FastHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const noexcept {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return (size_t)splitmix64(x + FIXED_RANDOM);
    }
};

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

        // Reserve maps once to avoid rehashing a lot.
        unordered_map<ll, ll, FastHash> cnt_all, cnt_no_x;
        cnt_all.reserve(1024);
        cnt_no_x.reserve(1024);
        cnt_all.max_load_factor(0.7f);
        cnt_no_x.max_load_factor(0.7f);

        ll total_all = 0;
        ll total_no_x = 0;
        ll cur = 0;

        // start a new block:
        cnt_all.clear(); cnt_no_x.clear();
        cnt_all[0] = 1;   // empty prefix inside block
        cnt_no_x[0] = 1;  // empty prefix since last x

        for (int i = 0; i < n; ++i) {
            if (a[i] > x) {
                // reset block
                cur = 0;
                cnt_all.clear();
                cnt_no_x.clear();
                cnt_all[0] = 1;
                cnt_no_x[0] = 1;
                continue;
            }
            cur += a[i];
            // count all subarrays in current block that end here and have sum == s
            auto it_all = cnt_all.find(cur - s);
            if (it_all != cnt_all.end()) total_all += it_all->second;
            cnt_all[cur] += 1;

            if (a[i] < x) {
                // can extend "no-x" segment
                auto it_no = cnt_no_x.find(cur - s);
                if (it_no != cnt_no_x.end()) total_no_x += it_no->second;
                cnt_no_x[cur] += 1;
            } else {
                // a[i] == x, subarrays ending here contain x so
                // reset the "no_x" prefix-counts to start after this position.
                cnt_no_x.clear();
                // start new no-x segment with prefix sum cur (empty suffix after this pos)
                cnt_no_x[cur] = 1;
            }
        }

        cout << (total_all - total_no_x) << '\n';
    }
    return 0;
}
