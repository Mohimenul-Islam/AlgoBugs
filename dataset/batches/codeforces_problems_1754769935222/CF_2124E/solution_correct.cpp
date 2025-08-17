#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;
const int MOD = 1e9+7;


void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0LL);
    int mx = *max_element(a.begin(), a.end());
    if(sum & 1 || mx*2 > sum) {
        cout << -1 << '\n';
        return;
    }
    int cur = 0, pos = 1;
    for(; pos <= n; pos++){
        if(cur + a[pos] > sum/2){
            pos--;
            break;
        }
        cur += a[pos];
    }
    if(cur == sum/2){
        cout << 1 << '\n';
        for(int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    cout << 2 << '\n';
    int x = sum/2 - cur, y = sum/2 - (sum - cur - a[pos+1]);
    vector<int> ans1(n+5);
    ans1[pos+1] = x;
    a[pos+1] -= x;
    int left = x;
    for(int i = pos+2; i <= n; i++){
        if(a[i] >= left){
            a[i] -= left;
            ans1[i] = left;
            break;
        }else{
            ans1[i] = a[i];
            left -= a[i];
            a[i] = 0;
        }
    }
    for(int i = 1; i <= n; i++) cout << ans1[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


	int T = 1; cin >> T;
	while(T--) solve();

    return 0;
}
