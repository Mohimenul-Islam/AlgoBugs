#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static long long count_leq(const vector<long long>& a, long long s, long long K) {
    unordered_map<long long, long long> freq;
    freq.reserve(a.size() * 2 + 10);

    long long ans = 0, pref = 0;
    freq[0] = 1;                          // start of a valid segment

    for (long long v : a) {
        if (v > K) {                      // cut segment at a value > K
            pref = 0;
            freq.clear();
            freq[0] = 1;
            continue;
        }
        pref += v;
        auto it = freq.find(pref - s);
        if (it != freq.end()) ans += it->second;
        ++freq[pref];
    }
    return ans;
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
