#include <bits/stdc++.h>
#define f(i,n) for(ll i=0;i<n;i++)
#define ll long long
#define pb push_back

using namespace std;
const ll mod  = 1e9 + 7;
ll n,m,root;
vector<vector<ll>>v;
vector<bool>vis,leaf;
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
        else ret=ret*(nx++)%mod;
    }
    if(nonleafs>2)return 0;
    if(nonleafs==2&&nod!=root)return 0;
    if(nonleafs&&nod==root)ret=ret*2%mod;
    return ret;
}
void solve_case(){
    cin>>n>>m;
    v.clear();v.resize(n+1);
    vis.clear();vis.resize(n+1,0);
    sz.clear();sz.resize(n+1,0);
    leaf.clear();leaf.resize(n+1,0);
    for(ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        v[x].pb(y);v[y].pb(x);
    }

    if(m+1!=n){
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        leaf[i]=v[i].size()==1;
    }
    root=1;
    for(int i=1;i<=n;i++){
        if(leaf[i])continue;
        int nonleafs=0;
        for(auto x:v[i]){
            nonleafs+=1-leaf[x];
        }
        root=i;
        if(nonleafs)break;

    }
    //cout<<root<<endl;
    cout<<(2*dfs(root,0))%mod<<endl;
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
4 2
4 3
4 1
6 5
1 2
1 3
1 4
4 5
4 6
6 5
1 2
3 2
2 4
4 5
4 6
*/
