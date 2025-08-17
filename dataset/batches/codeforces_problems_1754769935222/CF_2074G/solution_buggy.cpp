#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define I(x) for(auto&i:x)cin>>i
#define vll vector<ll>
#define vvll vector<vector<ll>>


void solve(){
    ll n; cin >> n;
    vll v(n); I(v);
    vvll dp(n, vll(n));
    for(int i = 0; i < n; ++i){
        for(int d = 2; d < n; ++d){
            int l = i, r = (i+d)%n;
            dp[l][r] = dp[(l+1)%n][r];
            for(int m = (l+1)%n; m != r; m=(m+1)%n){
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[(m+1)%n][r]);
                ll tri = v[l]*v[m]*v[r];
                if((n+m-l)%n >= 4) tri += dp[(l+1)%n][(n+m-1)%n];
                if((n+r-m)%n >= 4) tri += dp[(m+1)%n][(n+r-1)%n];
                dp[l][r] = max(dp[l][r], tri);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = (i+1)%n; j != i; j=(j+1)%n){
            for(int k = (j+1)%n; k != i; k=(k+1)%n){
                ans = max(ans, dp[i][(n+j-1)%n] + dp[j][(n+k-1)%n] + dp[k][(n+i-1)%n]);
                ll tri = v[i] * v[j] * v[k];
                if((n+j-i)%n >= 4) tri += dp[(i+1)%n][(n+j-1)%n];
                if((n+k-j)%n >= 4) tri += dp[(j+1)%n][(n+k-1)%n];
                if((n+i-k)%n >= 4) tri += dp[(k+1)%n][(n+i-1)%n];
                ans = max(ans, tri);
            }
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
}