#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
void solve()
{
    int n,s,x;cin>>n>>s>>x;
    int a[n+1];
    int sum[n+1]={0};
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    int left=1;
    unordered_map<int,int>q;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>x){
            q.clear();
            left=i+1;
        }else if(a[i]==x){
            while(left<=i) q[sum[left-1]]++,left++; 
        }
        ans+=q[sum[i]-s];
    }
    cout<<ans<<endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
        solve();
}