#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin()+1,a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);
#define int long long
using namespace std;
constexpr int maxn=2e5+10,inf=1e18;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),dp(n+1,0);
    rep(i,1,n)cin>>a[i];
    dp[1]=1;
    rep(i,2,n){
        if(a[i]>a[i-1])dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1]+i;
    }
    int ans=accumulate(all(dp),0ll);
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
}