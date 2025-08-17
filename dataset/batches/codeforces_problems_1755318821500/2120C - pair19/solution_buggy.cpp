#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
const int mod = 1e9+7;
const int N = 1e6+10;

void solve() {
    int n,m;
    cin >> n >> m;
    if(m < n||m > (n*(n+1))/2) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    vector<int> ans, st(n+1);
    for(int i = n; i >= 1; i --) {
        if(m-i >= n-cnt-1) {
            m -= i;
            cnt += 1;
            ans.push_back(i);
            st[i] = 1;
            if(m-i == n-cnt-1) break;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(st[i] == 0) ans.push_back(i);
    }
    cout << ans[0] << endl;
    for(int i = 0; i < ans.size()-1; i++) {
        cout << ans[i] << ' ' << ans[i+1] << endl;
    }
}    

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}