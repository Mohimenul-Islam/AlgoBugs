#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define ld long double
#define PII pair<int,int>
#define mod 1000000007
#define INF 1e18+9
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
#define yn(c) (c) ? yes() : no()
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define inpt(a, n) for(int i=0; i<n; i++) cin >> a[i];

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}
 
int powm(int a, int b){
    a %= mod;
    if(b == 0)
        return 1;
    int p = powm(a, b/2)%mod;
    p = (p*p)%mod;
    if(b%2)
        return (p*(a%mod))%mod;
    else
        return p;
}
 
int inv(int a){
    return powm(a, mod-2);
}

int solve(int n, int p){
    int ans = 0;
    while(n){
        ans = (ans * (p%mod))%mod;
        ans = (ans + (n%p))%mod;
        n /= p;
    }
    return ans;
}

const int INV2 = inv(2), INV6 = inv(6);

int sum1(int r){
    if(!r) return 0;
    int ans = (r * (r + 1))%mod;
    ans = (ans * INV2)%mod;
    return ans;
}

int sum1(int l, int r){
    if(l > r) return 0;
    return (sum1(r) - sum1(l-1) + mod)%mod;
}

int sum2(int r){
    if(!r) return 0;
    int ans = (r * (((r + 1) * (2*r + 1))%mod))%mod;
    ans = (ans * INV6)%mod;
    return ans;
};

int sum2(int l, int r){
    return (sum2(r) - sum2(l-1) + mod)%mod;
};

void solve(){
    int n, k; cin >> n >> k;
    int sqrt = max((ld)2, floor(sqrtl(n)));

    int p = 2, ans = 0;
    for(; p <= min(sqrt, k); p++)
        ans = (ans + solve(n, p))%mod;

    while(p <= min(n, k)){
        int val = n/p;
        int np = min(n/val, k) + 1;
        ans = (ans + ((np - p)*val)%mod)%mod;
        ans = (ans - (sum2(p, np-1) * val)%mod + mod)%mod;
        ans = (ans + (n * sum1(p, np-1))%mod)%mod;
        p = np;
    }
    
    if(p <= k)
        ans = (ans + (n*((k-p+1)%mod))%mod)%mod;

    cout << ans << endl;
}

signed main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0);
#endif
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}