#include <bits/stdc++.h>
#define f(i,n) for(ll i=0;i<n;i++)
#define ll long long
#define pb push_back

using namespace std;
const ll mod  = 1e9 + 7;
ll n,m;
vector<vector<ll>>v;
vector<bool>vis;
vector<ll>sz;

ll dfs(ll nod,ll par){
    sz[nod]=1;
    vis[nod]=1;
    ll nonleafs=0;
    ll ret=1,nx=1;
    for(auto x:v[nod]){
        if(x==par)continue;
        if(vis[x])return 0;
        ret=ret*dfs(x,nod)%mod;
        sz[nod]+=sz[x];
        if(sz[x]>1)nonleafs++;
        else ret=ret*nx++%mod;
    }
    if(nonleafs>2)return 0;
    if(nonleafs==2&&nod!=1)return 0;
    if(nonleafs&&nod==1)ret=ret*2%mod;
    return ret;
}
void solve_case(){
    cin>>n>>m;
    v.clear();v.resize(n+1);
    vis.clear();vis.resize(n+1,0);
    sz.clear();sz.resize(n+1,0);
    for(ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        v[x].pb(y);v[y].pb(x);
    }
    if(m+1!=n){
        cout<<0<<endl;
        return;
    }
    /*
    for(ll i=1;i<=n;i++){
        cout<<i<<": "<<vis[i]<<' '<<sz[i]<<endl;
        for(auto x:v[i])cout<<x<<' ';
        cout<<endl;
    }
    */
    cout<<(2*dfs(1,0))%mod<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve_case();
    }
    return 0;
}
/*
10
3 3
1 2
2 3
3 1
4 3
1 2
1 3
1 4
6 5
1 2
1 3
1 4
4 5
4 6
*/
