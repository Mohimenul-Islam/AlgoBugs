#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll fact[(ll)2e5+10];

void make_fact(){
    fact[0] = 1;
    for(int i=1;i<=(ll)2e5+5;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=MOD;
    }
}
int nodes_visited_0 = 0;
int nodes_visited_1 = 0;

int  multi_node = -1;
void dfs_get_multi_node(vector<int> adj[],int node,int from){
    
    if(adj[node].size()>1){
        multi_node = node;
        return;
    }
    for(auto u:adj[node]){
        if(u==from)continue;
        dfs_get_multi_node(adj,u,node);
    }
}

ll dfs(vector<int> adj[],int node,int from,vector<bool> &visited,int color){
    ll val = 1;
    visited[node] = true;
    int num_single = 0;
    if(color==0)nodes_visited_0++;
    else nodes_visited_1++;
    for(auto u:adj[node]){
        if(u==from) continue;
        if(visited[u]) return 0;
        if(adj[u].size()==1){
            num_single++;
        }
        val*=dfs(adj,u,node,visited,1-color);
        val%=MOD;
    }
    if(adj[node].size()-num_single>2){
        //it means the the nodes connected to this node that arent leaft are >=3 and they must coincide in this case
        return 0;
    }
    val*=fact[num_single];
    val%=MOD;
    return val;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 1;
    int num_components = 0;
    vector<bool> visited(n+1,false);
    for(int i= 1;i<=n;i++){
        if(!visited[i]){
            nodes_visited_0=0;
            nodes_visited_1=0;
            multi_node= -1;
            dfs_get_multi_node(adj,i,-1);
            if(multi_node!=-1)ans*=dfs(adj,multi_node,-1,visited,0);
            else{
                ans*=dfs(adj,i,-1,visited,0);
            }
                
            ans%=MOD;
            ans*=2;//for up and down change
            ans%=MOD;
            if(nodes_visited_0>1 && nodes_visited_1>1){
                ans*=2;
                ans%=MOD;
            }
            num_components++;
        }
    }
    ans*=fact[num_components];
    ans%=MOD;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    make_fact();
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}