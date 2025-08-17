#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int p[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i];

        vector<int>sum(n+5);
        sum[1]=1;
        if(p[1]>p[2]) sum[2]=3;
        else sum[2]=2;
        long long ans=0;
        ans+=sum[1]+sum[2];
        for(int i=3;i<=n;i++){
            if(p[i-1]>p[i]) sum[i]=i+sum[i-1];
            else sum[i]=sum[i-1]+1;
            ans+=sum[i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}