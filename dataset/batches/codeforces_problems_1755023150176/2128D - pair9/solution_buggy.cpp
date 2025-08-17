#include<bits/stdc++.h>
#define endl '\n'
#define forr(i,l,r) for(int i=l;i<=r;i++)
#define reforr(i,l,r) for(int i=r;i>=l;i--)
#define int long long
using namespace std;
const int N=15,M=1e9+7;
int dp[N];
void solve(){
	int n;cin>>n;
    memset(dp,0,sizeof dp);
    vector<int>p(n+1);
    forr(i,1,n)cin>>p[i];
    dp[1]=1;
    forr(i,2,n){
        if(p[i]<p[i-1])dp[i]=i+dp[i-1];
        else dp[i]=dp[i-1]+1;
    }
    int sm=0;
    forr(i,1,n)sm+=dp[i];
    cout<<sm<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	int t=1;
    cin>>t;
	while(t--) solve();
	
} 
