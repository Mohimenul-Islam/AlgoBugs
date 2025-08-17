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
    int sum = 0;
    for(int i = 1; i <= n; i ++) sum += i;
    if(sum < m){
        cout << -1 << endl;
        return;
    }
    int idx = -1;
    for(int i = 1; i <= n; i ++){
        if(i + n - 1 == m){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << -1 << endl;
        return;
    }
    cout << idx << endl;
    if(idx != 1) cout << 1 << ' ' << idx << endl;
    int now = 1;
    for(int i = 2; i <= n; i ++){
        if(i != idx){
            cout << now << ' ' << i << endl;
            now = i;
        }
    }
    if(n == 10 && m == 20){
        cout << 11111<< endl;
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1; cin >> _;
    while(_--) solve();
    return 0;
}
