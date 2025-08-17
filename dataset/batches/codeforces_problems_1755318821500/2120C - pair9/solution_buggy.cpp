#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n, m;
    cin >> n >> m;
    LL cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += i;
        if((n - i) * i + cnt < m) continue;
        if(n - 1 + i > m) continue;
        else {
            LL dlt = (n - i) * i + cnt - m;
            vector <pair<int, int>> ans;
            ans.push_back({i, 1});
            for(int j = i + 1; j <= n; j++) {
                if(dlt > i - 1) {
                    ans.push_back({1, j});
                    dlt -= i - 1;
                }
                else {
                    int id = i - dlt;
                    ans.push_back({id, j});
                    dlt = 0;
                }
            }

            for(int j = i - 1; j >= 2; j--) {
                if(dlt > j - 1) {
                    dlt -= j - 1;
                    ans.push_back({1, j});
                }
                else if(dlt == 0) {
                    ans.push_back({i, j});
                }
                else {
                    int id = j - dlt;
                    ans.push_back({id, j});
                    dlt = 0;
                }
            }

            cout << i << '\n';
            for(auto[u, v]: ans) cout << u << ' ' << v << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}