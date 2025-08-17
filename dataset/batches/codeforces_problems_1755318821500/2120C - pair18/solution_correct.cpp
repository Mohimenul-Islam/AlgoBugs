#include<bits/stdc++.h>
#define int long long
// #define x first
// #define y second
#define ls (x << 1)
#define rs (x << 1 | 1)
using namespace std;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int , int>;
const int N = 2e3 + 9;
const int M = 1e6 + 9;
const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 240011539;
// const ll inf = 1e18;
const int P = 13331;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-15;

void solve(){
    int n , m; cin >> n >> m;
    if(n * (n + 1) / 2 < m || m < n){
        cout << -1 << endl;
        return;
    }
    for(int k = n; k >= 1; k --){
        int t = (n + k) * (n - k + 1) / 2 + k - 1;
        if(t >= m){
            int idx = k - (t - m);// (t - m)是需要减少的值
            if(k == n){
                cout << idx << endl;
            }else{
                cout << n << endl;
                for(int j = n; j >= k + 2; j --){
                    cout << j << ' ' << j - 1 << endl;
                }
                cout << k + 1 << ' ' << idx << endl;
            }
            if(idx > 1){
                cout << idx << ' ' << 1 << endl;
            }
            for(int j = 1 , last = 1; j <= k; j ++){
                if(j == last || j == idx) continue;
                cout << last << ' ' << j << endl;
                last = j;
            }
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1; cin >> _;
    while(_--) solve();
    return 0;
}
