#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TruongPham int main()

TruongPham {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        ll s, x;
        int n;
        cin >> n >> s >> x;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<vector<ll>> vt;
        int index = 1;
        while (index <= n) {
            if (a[index] > x) {
                index++;
                continue;
            }
            vector<ll> tmp;
            while (index <= n && a[index] <= x) {
                tmp.push_back(a[index]);
                index++;
            }
            vt.push_back(tmp);
        }

        ll ans = 0;
        for (auto& now : vt) {
            int len = now.size();
            now.insert(now.begin(), 0);
            vector<ll> sum(len + 2);
            for (int j = 1; j <= len; j++) sum[j] = sum[j - 1] + now[j];

            unordered_map<ll, vector<int>> pos;
            pos[0].push_back(1);
            int last_pos = -1;
            for (int j = 1; j <= len; j++) {
                if (now[j] == x) last_pos = j;
                auto& position = pos[sum[j] - s];
                int place = upper_bound(position.begin(), position.end(), last_pos) - position.begin();
                ans += place;
                pos[sum[j]].push_back(j + 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
