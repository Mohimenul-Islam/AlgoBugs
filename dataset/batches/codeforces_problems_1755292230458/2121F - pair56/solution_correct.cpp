#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// fast hash to avoid hacking and speed up unordered_map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
        return (size_t)splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    // Reserve a reasonably large capacity for the global map (sum n <= 2e5)
    unordered_map<ll,int,custom_hash> cnt;
    cnt.reserve(1 << 18);
    cnt.max_load_factor(0.7);

    while (t--) {
        int n; ll s, x;
        cin >> n >> s >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll answer = 0;
        vector<ll> used_keys; // keys inserted into cnt, to clear later cheaply

        auto insert_cnt = [&](ll key, int delta){
            auto it = cnt.find(key);
            if (it == cnt.end()) {
                cnt.emplace(key, delta);
                used_keys.push_back(key);
            } else it->second += delta;
        };
        auto get_cnt = [&](ll key)->int{
            auto it = cnt.find(key);
            return (it == cnt.end() ? 0 : it->second);
        };
        auto reset_cnt = [&](){
            for (ll k : used_keys) cnt.erase(k);
            used_keys.clear();
        };

        int i = 0;
        while (i < n) {
            if (a[i] > x) { ++i; continue; }
            int j = i;
            while (j < n && a[j] <= x) ++j; // block [i..j-1]
            // count all subarrays with sum s in block
            reset_cnt();
            insert_cnt(0, 1);
            ll cur = 0, total_in_block = 0;
            for (int idx = i; idx < j; ++idx) {
                cur += a[idx];
                total_in_block += (ll)get_cnt(cur - s);
                insert_cnt(cur, 1);
            }

            // subtract subarrays that lie completely inside segments with all elements < x
            ll subtract = 0;
            int pos = i;
            while (pos < j) {
                if (a[pos] == x) { ++pos; continue; }
                int start = pos;
                while (pos < j && a[pos] < x) ++pos;
                int end = pos - 1;
                // count subarrays with sum s inside [start..end]
                reset_cnt();
                insert_cnt(0, 1);
                cur = 0;
                for (int idx = start; idx <= end; ++idx) {
                    cur += a[idx];
                    subtract += (ll)get_cnt(cur - s);
                    insert_cnt(cur, 1);
                }
            }

            answer += (total_in_block - subtract);
            reset_cnt();
            i = j;
        }

        cout << answer << '\n';
    }
    return 0;
}
