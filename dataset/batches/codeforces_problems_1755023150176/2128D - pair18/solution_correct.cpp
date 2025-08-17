#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 #define int long long
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
const int N = 0x7fffffff;
const int mod = 1e9 + 7;
const int X4[4] = {1, -1, 0, 0}, Y4[4] = {0, 0, 1, -1};



void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 5);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (i * (n - i + 1));
        if (i != n && nums[i + 1] > nums[i]) ans -= i * (n - i);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}