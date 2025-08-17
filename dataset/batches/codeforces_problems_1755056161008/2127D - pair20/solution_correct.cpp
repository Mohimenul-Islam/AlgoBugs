#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
vector<int>adj[200005],color(200005),c(200005,1);
int ans,b;
int mul(int a,int b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
void dfs(int node,int p)
{
    int num=0;
    b+=color[node];
    for(auto u:adj[node])
    {
        if(adj[u].size()==1)num++;
        if(u!=p)
        {
            if(color[u]!=-1){ans=0;continue;}
            color[u]=1-color[node];
            dfs(u,node);
        }
    }
    if(adj[node].size()-num>2)ans=0;
    ans=mul(ans,c[num]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i<=200000;i++)c[i]=mul(i,c[i-1]);
    int t;
    cin>>t;
    while(t--)
    {
        ans=1;
        b=0;
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            color[i]=-1;
            adj[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        color[1]=1;
        dfs(1,1);
        if(b>1&&b<n-1)ans=mul(ans,2);
        ans=mul(ans,2);
        cout<<ans<<'\n';
    }
}
