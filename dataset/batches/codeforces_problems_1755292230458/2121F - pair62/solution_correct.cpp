#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define DEBUGLN(x) cout << #x << " = " << x << '\n';
#define CONTAINER_DEBUGLN(x, l, r) cout << #x << " = [ "; for (int i = l; i <= (int)r; i ++) cout << x[i] << ' '; cout << "]\n";
#define CUSTOM_CONTAINER_DEBUGLN(x, l, r, what) cout << #x << " = [ "; for (int i = l; i <= (int)r; i ++) cout << (what) << ' '; cout << "]\n";

#define int long long

void solve(int case_index) {
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    auto calc = [&](int x) {
        map<int, int> mp;
        int cnt = 0;
        mp[0] = 1;
        for (int i = 1; i <= n; i ++) {
            if (a[i] > x) mp.clear();
            cnt += mp[sum[i] - s];
            mp[sum[i]] ++;
        }
        return cnt;
    };

    cout << calc(x) - calc(x - 1) << '\n';
}

signed main() {
    int T; cin >> T; for (int i = 0; i < T; i ++) solve(i);
    return 0;
}