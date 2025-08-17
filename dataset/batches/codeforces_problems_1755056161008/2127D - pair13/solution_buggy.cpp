#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials
    vector<i64> dp(1e5 + 10);
    dp[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        dp[i] = (dp[i - 1] * i) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> ed(n);
        vector<int> deg(n, 0);

        for (int i = 0; i < m; i++) {
            int xx, yy;
            cin >> xx >> yy;

            // Adjust to 0-indexed if input is 1-indexed
            // Remove this line if your input is already 0-indexed
            xx--, yy--;

            // Safety check
            if (xx < 0 || yy < 0 || xx >= n || yy >= n) {
                cerr << "Invalid vertex index in input\n";
                return 0;
            }

            ed[xx].push_back(yy);
            ed[yy].push_back(xx);
            deg[xx]++;
            deg[yy]++;
        }

        // Special case: only 1 edge
        if (m == 1) {
            cout << 2 << "\n";
            continue;
        }

        vector<int> check;
        for (int i = 0; i < n; i++) {
            if (deg[i] >= 2) check.push_back(i);
        }

        i64 ans = 1;
        int ct = 0;
        vector<int> ft;
        bool invalid = false;
        bool handled = false;

        for (int idx : check) {
            int x = 0;
            for (int neighbor : ed[idx]) {
                if (deg[neighbor] >= 2) x++;
                if (x > 2) {
                    invalid = true;
                    break;
                }
            }
            if (invalid) break;

            if (x == 0) {
                if (deg[idx] == m) {
                    cout << (2 * dp[deg[idx]]) % MOD << "\n";
                } else {
                    cout << 0 << "\n";
                }
                handled = true;
                break;
            }
            if (x == 1) {
                ct++;
                ft.push_back(deg[idx] - 1);
            }
            if (x == 2) {
                ft.push_back(deg[idx] - 2);
            }
        }

        if (handled) continue;
        if (invalid || ct <= 1) {
            cout << 0 << "\n";
            continue;
        }

        if (ct == 2) {
            for (int val : ft) {
                ans = (ans * dp[val]) % MOD;
            }
            cout << (4 * ans) % MOD << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}
