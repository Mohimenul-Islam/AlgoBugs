#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define LightningMcQueen ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define nl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
#define ll long long
#define ull unsigned long long int
#define vi vector<int>
#define vll vector<long long int>
#define vb vector<bool>
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define mll map<long long int,long long int>
#define sll set<long long int>
#define sc set<char>
 
#define bs binary_search
#define pb push_back
#define vsort sort(v.begin(),v.end());
#define vsortd sort(v.begin(),v.end(),greater<int>());
#define rep(i,k,n) for(ll i=k; i<n; i++)
#define rrep(i,x,y) for(ll i=x; i>=y; i--)
#define CEIL(x,y) (ll)ceil(1.0*x/y)
 
// const int N = 1e5 + 5;
const ll M = (ll)(1e9+7);
const ll MM = (ll)998244353;
const ll INF = 1e9;
 
#define PI 3.1415926535897932384626433832795
 
ll binpow(ll a,ll b){
  a=a%MM;
  ll ans=1;
  while(b>0)
  {
    if(b%2!=0)
    {
      ans=((ans%MM)*(a%MM))%MM;
    }
    a=((a%MM)*(a%MM))%MM;
    b=b>>1;
  }
  return ans;
}
 
ll GCD(ll a, ll b)
{
  if(!b)
  return a;
  else
  return GCD(b,a%b);
}
 
bool isPrime(ll x)
{
  if(x<2)
  return false;
  else
  for(ll i=2;i*i<=x;i++)
  {
    if(x%i==0)
    return false;
  }
  return true;
}
ll mod_nCk(ll n,ll k)
{
  ll den=1,num=1;
  rep(i,1,k+1)
  {
    den=(den*i)%M;
    num=(num*(n-i+1))%M;
  }
  ll ans=(num*(binpow(den,M-2)))%M;
  return ans;
}
ll find_mex(vll &arr)
{
  //array is by ref 
  ll sz=arr.size();
  if(sz==0) return -1;
  sort(arr.begin(),arr.end());
  if(arr[0]!=0)
  return 0;
  rep(i,0,sz-1)
  {
    if((arr[i+1]-arr[i])>1)
    return arr[i]+1;
  }
  return arr[sz-1]+1;
}
// struct compare {  
//  bool operator()(const pair<int, int>& value, 
//         const int& key) 
//  { 
//   return (value.first < key); 
//  } 
//  bool operator()(const int& key, 
//      const pair<int, int>& value) 
//  { 
//   return (key < value.first); 
//  } 
// }; 
 
bool check_bipap_dfs(ll node,ll col,vector<vector<ll> > &g,vll &color,vll &vis)
{
  color[node]=col;
  ll sz=g[node].size();
  vis[node]=1;
  rep(i,0,sz)
  {
    if(color[g[node][i]]==-1)
    {
      vis[g[node][i]]=1;
      if(check_bipap_dfs(g[node][i],!col,g,color,vis)==false) return false;
    }
    else if(color[g[node][i]]==col) return false;
  }
  return true;
}
bool check_bipap_bfs(ll v,vector<vector<ll> > &g,vll &color,vll &vis,queue<pair<ll,ll>> &q)
{
  q.push({v,0});
  color[v]=0;
  vis[v]=0;
  while(!q.empty())
  {
    ll node=q.front().first;
    ll col=q.front().second;
    q.pop();
    ll sz=g[node].size();
    rep(i,0,sz)
    {
      if(color[g[node][i]]==col)
      return false;
      else if(color[g[node][i]]==-1)
      {
        q.push({g[node][i],col^1});
        color[g[node][i]]=col^1;
        vis[g[node][i]]=1;
      }
    }
  }
  return true;
}
// you can check cycle in DG using dfs by maintaining a pathVIS array 
// topo sort size == node we can say no it do not have a cycle in DG so its DAG
// u->v  linear ordering such that u always appears before v in that ordering 
//dfs topo sort is done using stack
vector<ll> topo_sort_bfs(ll n,vector<vector<ll> > &g) //kahn's algo
{
  // below code is for vertex 1 to n
  vll topo,indegree(n+1,0);
  queue<ll> q;
  ll size=g.size();
  rep(i,0,size)
  {
    ll sz=g[i].size();
    rep(j,0,sz)
    indegree[g[i][j]]++;
  }
  rep(i,1,n+1)
  {
    if(indegree[i]==0)
    q.push(i);
  }
  while(!q.empty())
  {
    ll node=q.front();
    q.pop();
    topo.pb(node);
    ll sz=g[node].size();
    rep(i,0,sz)
    {
      indegree[g[node][i]]--;
      if(indegree[g[node][i]]==0)
      q.push(g[node][i]);
    }
  }
  return topo;
}
//n-->no. of vertices (1 to n) 
vector<ll> shortest_path_weighthed_DAG(ll source,ll n,vector<vector<pair<ll,ll>> > &g)
{
  vll topo; //to do weighted graph write code just like above or use dfs+stack
  // size will be n
  vll dis(n+1,1e17);
  dis[source]=0;
  rep(i,0,n)
  {
    ll node=topo[i];
    ll sz=g[node].size();
    ll distance_so_far=dis[node];
    rep(j,0,sz)
    {
      dis[g[node][j].first]=min(dis[g[node][j].first],distance_so_far+g[node][j].second);
    }
  }
  return dis;
  //note : if not reachable then dis[i]>=1e17 
}
//for undirected unity weight graph normal bfs will work pair queue will be used
//dijikstra algo (it does not work in negative weights/cycles reason---> goes in infinite loop)
vector<ll> dijikstra(ll source,ll n,vector<vector<pair<ll,ll>> > &g)
{
  vll dis(n+1,1e17);
  // we can do this using set with slightly better tc not much difference
  priority_queue< pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > pq;
  //dis,node  
  pq.push({0,source});
  dis[source]=0;
  while(!pq.empty())
  {
    ll distance=pq.top().first;
    ll node=pq.top().second;
    pq.pop();
    ll sz=g[node].size();
    if(distance!=dis[node])
    continue;
    rep(i,0,sz)
    {
      ll child=g[node][i].first;
      ll weight=g[node][i].second;
      if((distance + weight) < dis[child])
      {
        dis[child]=distance+weight;
        pq.push({dis[child],child});
      }
    }
  }
  return dis;
}
//if path weight is negative we call as negative cycle detected and use bellman ford algo instead of dijikstra 
//works on directed graphs (for undirected you have to explicitly convert in DG)
//why N-1 times iteration? ans-> if there is a answer existed worst case it needs n-1 time to get ans for all remaining nodes
//now if in nth iteration distance array changes means negative cycle
vector<ll> bellman_ford(ll source,ll n,vector<pair<ll,pair<ll,ll>>> &g)
{
  vll dis(n+1,1e17);
  dis[source]=0;
  ll m=g.size();
  rep(i,0,n-1) //N-1 iteration/relaxation of edges 
  {
    rep(j,0,m) // considering 1 to n nodes 
    { 
      ll u=g[j].first,v=g[j].second.first,wt=g[j].second.second;
      if((dis[u] + wt)<dis[v])
      {
        dis[v]=dis[u]+wt;
      }
    }
  }
  bool f=true;
  //nth relaxation
  rep(j,0,m) // considering 1 to n nodes 
    {  
      ll u=g[j].first,v=g[j].second.first,wt=g[j].second.second;
      if((dis[u] + wt)<dis[v])
      {
        f=false;
        break;
      }
    }
    if(!f) return {-1};
    return dis;
}
void floyd_warshall(ll n,vector<vector<ll> > &mallx)
{
  //mallx is adjacency mallx where i->j is denoted by weight else it should be 1e9
  //mallx[i][i]=0;
  //brute force
  rep(k,0,n+1)  //via k we are moving kinda dp
  {
    rep(i,0,n+1)
    {
      rep(j,0,n+1)
      {
        mallx[i][j]=min(mallx[i][j],mallx[i][k] + mallx[k][j]);
      }
    }
  }
  //ifmallx[i][i]<0 negative cycle
}
//prim's algorithm
ll min_spanning_tree(ll n,vector<vector<pair<ll,ll>> > &g)
{
  ll ans=0;
  vll vis(n+1,0);
  priority_queue< pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > pq;
  //wt,node pair (if it requires exact tree we store the parent)
  pq.push({0,1});  //assuming graph has 0 otherwise 1
  while(!pq.empty())
  {
    ll node=pq.top().second;
    ll wt=pq.top().first;
    pq.pop();
    //if(!vis[node])  ->  we add that node parent in our MST
    if(!vis[node])
    {
      vis[node]=1;
      ans+=wt;  //adding in our MST and saying it's visited
      ll sz=g[node].size();
      rep(i,0,sz)
      {
        if(!vis[g[node][i].first])
        pq.push({g[node][i].second,g[node][i].first});
        
      }
    }
  }
  return ans;
}
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
 
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
// map<ll,int,custom_hash> m;
 



// const ll p = 31;
// const ll p2 = 3628800 + 1;
// const ll mod = 1e9+9;
// ll mi;
// ll mi2;
// vector<ll> pw;
// vector<ll> pref_hash;
// vector<ll> suff_hash;
// vector<ll> pw2;
// vector<ll> pref_hash2;

// ll binpow(ll a,ll b,ll M){
// 	a%=M;
// 	ll ans=1;
// 	while(b>0)
// 	{
// 		if(b&1){
// 			ans*=a;
// 			ans %= M;
// 		}
// 		a*=a;
// 		a%=M;
// 		b>>=1;
// 	}
// 	return ans;
// }
// void createHash(string &s)
// {
// 	ll n = s.length();
// 	pw.resize(n+5);
//   pw2.resize(n+5);
// 	pw[0]=pw2[0]=1;
// 	for(ll i=1;i<=n;i++){
// 		pw[i] = (pw[i-1]*p);
// 		pw[i] %= mod;
//     pw2[i] = (pw2[i-1]*p2);
//     pw2[i] %= mod;
// 	}
// 	mi = binpow(pw[n],mod-2,mod);
//   mi2 = binpow(pw2[n],mod-2,mod);
// 	pref_hash.resize(n+5);
//   pref_hash2.resize(n+5);
// 	pref_hash[0] = pref_hash2[0] = (int)(s[0] - 'a') + 1;
// 	for(ll i=1;i<n;i++){
// 		pref_hash[i] = pref_hash[i-1] + (pw[i]*(((int)s[i]-'a') + 1));
// 		pref_hash[i] %= mod;
//     pref_hash2[i] = pref_hash2[i-1] + (pw2[i]*(((int)s[i]-'a') + 1));
// 		pref_hash2[i] %= mod;
// 	}
 
// 	suff_hash.resize(n+5);
// 	suff_hash[n-1] = (s[n-1]-'a') + 1;
// 	for(ll i=n-2;i>=0;i--){
// 		suff_hash[i] = suff_hash[i+1] + (pw[n-i-1]*(((int)s[i]-'a') + 1));
// 		suff_hash[i] %= mod;
// 	}
// }
 
// ll sub_pref(ll i,ll j,ll n)
// {
// 	ll hash = (pref_hash[j] - (i ? pref_hash[i-1] : 0) + mod)%mod;
// 	hash = (hash*pw[n-i])%mod;
// 	hash = (hash*mi)%mod;
// 	hash %= mod;
// 	return hash;
// }
// ll sub_pref2(ll i,ll j,ll n) {
//   ll hash = (pref_hash2[j] - (i ? pref_hash2[i-1] : 0) + mod)%mod;
// 	hash = (hash*pw2[n-i])%mod;
// 	hash = (hash*mi2)%mod;
// 	hash %= mod;
// 	return hash;
// }
// ll sub_suff(ll i,ll j,ll n)
// {
// 	ll hash = (suff_hash[i] - (j == n-1 ? 0 : suff_hash[j+1]) + mod)%mod;
// 	hash = (hash * pw[j+1])%mod;
// 	hash = (hash * mi)%mod;
// 	hash %=mod;
// 	return hash;
// }
// void build(vll &arr,vll &segTree,ll start,ll end,ll index)
// {
//   if(start==end) {segTree[index]=arr[start];return;}
//   ll mid=start+(end-start)/2;
//   build(arr,segTree,start,mid,2*index);
//   build(arr,segTree,mid+1,end,2*index + 1);
//   segTree[index]=segTree[2*index] + segTree[2*index + 1];
// }
// void update(vll &arr,vll &segTree,ll start,ll end,ll index,ll pos,ll val)
// {
//   if(start==end) {segTree[index]=val;arr[start]=val;return;}
//   ll mid=start+(end-start)/2;
//   if(pos<=mid) 
//   update(arr,segTree,start,mid,2*index,pos,val);
//   else
//   update(arr,segTree,mid+1,end,2*index+1,pos,val);
//   segTree[index]=segTree[2*index]+segTree[2*index+1];
// }
// ll query(vll &segTree,ll start,ll end, ll index,ll l,ll r)
// {
//   if(l<=start && r>=end) return segTree[index];
//   if(l>end || r<start) return 0;
//   ll mid=start+(end-start)/2;
//   ll leftans= query(segTree,start,mid,2*index,l,r);
//   ll rightans= query(segTree,mid+1,end,2*index+1,l,r);
//   return leftans+rightans;
// }
// 11-2 6-8


void dfs(ll node,ll parent,vector<vector<ll>> &g, bool &f,vector<bool> &vis2) {
  vis2[node] = true;
  ll cnt = 0;
  for(auto child : g[node]) {
    if(!vis2[child]) {
      if((int)g[child].size() > 1) cnt++;
      dfs(child,node,g,f,vis2);
    } 
  }
  if(cnt == 2 && parent != -1) f=false;
}

int main(){ 
  LightningMcQueen
  int tt=1; 
  cin>>tt;
  vector<ll> fact(200005,1);
  rep(i,2,200005) {
    fact[i] = (fact[i-1] * i)%M;
  }
  while(tt--)
  { 
    ll n,m;
    cin >> n >> m;
    vector<vector<ll> > g(n+1);
    vector<vector<ll>> chain(n+1);
    rep(i,0,m) {
      ll u,v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    // condition to check whether possible or not such kind of arrangements
    bool f=true;
    ll root = -1, temp_root = -1, sz = -1;
    rep(i,1,n+1) {
      ll cnt = 0;
      for(auto child : g[i]) {
        if((int)g[child].size() > 1) {
          cnt++;
          chain[i].pb(child);
        }
      }
      if(cnt > 2) f=false;
      else if(cnt == 2 && root == -1) {
        root = i;
      } 
      else{
        if((int)g[i].size() > sz)
        {
          temp_root = i;
          sz = g[i].size();
        }
      }
    }
    //cycle check
    if(m>=n) f=false;
    vector<bool> vis2(n+1,false);
    if(root != -1)
    dfs(root,-1,g,f,vis2);
    vector<bool> vis(n+1,false);
    if(!f) cout << 0 << nl;
    else {
      // cout << root << "erve" << temp_root << nl;
      if(root == -1) root = temp_root;
      if((int)chain[root].size() == 0) {cout << (2*fact[g[root].size()])%M << nl; continue;}
      ll left_chain = chain[root][0], right_chain = (int)chain[root].size()==2 ? chain[root][1] : -1 ;
      ll ans = 1;
      if((int)g[root].size() <= 2) ans = fact[(int)g[root].size()];
      else {
        ll child_nodes = g[root].size();
        ans = (ans * (right_chain == -1 ? fact[child_nodes - 1] : fact[child_nodes - 2]))%M;
      }
      vis[root] = true;
      while(left_chain != -1 || right_chain != -1) {
        if(left_chain != -1) {
          ll left_chain_nodes = g[left_chain].size() - 1;
          if((int)chain[left_chain].size() > 0 && !vis[chain[left_chain][0]]) {
            if(left_chain_nodes > 1) ans = (ans * fact[left_chain_nodes - 1])%M;
            vis[left_chain] = true;
            left_chain = chain[left_chain][0];
          } 
          else {
            ans = (ans * fact[left_chain_nodes])%M;
            left_chain = -1;
          }
        }
        if(right_chain != -1) {
          if(right_chain != -1) {
          ll right_chain_nodes = g[right_chain].size() - 1;
          if((int)chain[right_chain].size() > 0 && !vis[chain[right_chain][0]]) {
            if(right_chain_nodes > 1) ans = (ans * fact[right_chain_nodes - 1])%M;
            vis[right_chain] = true;
            right_chain = chain[right_chain][0];
          } 
          else {
            ans = (ans * fact[right_chain_nodes])%M;
            right_chain = -1;
          }
          }
        }
      }
      cout << (4*ans)%M << nl;
    }
  }  
  return 0;
 } 