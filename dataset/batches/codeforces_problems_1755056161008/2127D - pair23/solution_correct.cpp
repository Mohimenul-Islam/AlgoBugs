// ===================== CP Template (C++17/20) =====================
// Tips:
//  - Toggle MULTI_TESTS for multiple test cases.
//  - Change MOD if needed; comb.init(N) must cover max n for nCr.
//  - Compile: g++ -std=gnu++17 -O2 -pipe -static -s main.cpp -o main
//  - For local debug: add -DLOCAL
// =================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

constexpr ll  INF64 = (ll)4e18;
constexpr int INF32 = (int)2e9;
constexpr int MOD   = 1'000'000'007;     // change if needed
constexpr int MOD2  = 998'244'353;

#define all(x) begin(x), end(x)
#define sz(x)  (int)(x).size()

// ----------- Debug (prints to cerr when compiled with -DLOCAL) -----------
#ifdef LOCAL
template<class T> void _dbg_one(const T& x){ cerr<<x; }
template<class A, class B> ostream& operator<<(ostream& os, const pair<A,B>& p){
    return os<<'('<<p.first<<','<<p.second<<')';
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){
    os<<'['; for (int i=0;i<sz(v);++i){ if(i) os<<','; os<<v[i]; } return os<<']';
}
template<class T> ostream& operator<<(ostream& os, const set<T>& v){
    os<<'{'; bool f=1; for (auto &e:v){ if(!f) os<<','; os<<e; f=0; } return os<<'}';
}
template<class K,class V> ostream& operator<<(ostream& os, const map<K,V>& m){
    os<<'{'; bool f=1; for (auto &e:m){ if(!f) os<<','; os<<e.first<<':'<<e.second; f=0; } return os<<'}';
}
#define dbg(...) do{ cerr<<"[", _dbg(#__VA_ARGS__, __VA_ARGS__); }while(0)
template<typename T> void _dbg(const char* name, T&& value){
    cerr<<name<<"] = "<<value<<"\n";
}
template<typename T, typename... Ts>
void _dbg(const char* names, T&& value, Ts&&... args){
    const char* comma = strchr(names+1, ',');
    cerr.write(names, comma-names) << "] = " << value << " | ";
    _dbg(comma+2, args...);
}
#else
#define dbg(...)
#endif

// -------------------- Random & Hash --------------------
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
struct CustomHash {
    static ull splitmix64(ull x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(ull x) const {
        static const ull FIXED_RANDOM = (ull)chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<class T> size_t operator()(const T& x) const { return splitmix64(std::hash<T>{}(x)); }
};

// -------------------- PBDS ordered_set --------------------
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// functions: os.order_of_key(x), *os.find_by_order(k)

// -------------------- Helpers --------------------
template<class T> inline bool chmin(T& a, const T& b){ if(b<a){ a=b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b){ if(a<b){ a=b; return true; } return false; }

ll mod_pow(ll a, ll e, ll m=MOD){
    ll r=1%m; a%=m; while(e){ if(e&1) r=(__int128)r*a % m; a=(__int128)a*a % m; e>>=1; } return r;
}
ll mod_inv(ll a, ll m=MOD){ return mod_pow((a%m+m)%m, m-2, m); } // MOD must be prime

// -------------------- Combinatorics (nCr mod MOD) --------------------
struct Comb {
    vector<ll> fac{1}, ifac{1};
    void init(int n){ // precompute up to n
        fac.resize(n+1); ifac.resize(n+1);
        fac[0]=1; for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
        ifac[n]=mod_inv(fac[n]); for(int i=n;i>0;i--) ifac[i-1]=ifac[i]*i%MOD;
    }
    ll C(int n,int r) const {
        if(r<0||r>n) return 0;
        return fac[n]*ifac[r]%MOD*ifac[n-r]%MOD;
    }
} comb;

// -------------------- Fenwick (BIT) --------------------
template<typename T>
struct Fenwick {
    int n; vector<T> bit;
    Fenwick(int n=0){ init(n); }
    void init(int n_){ n=n_; bit.assign(n+1, T{}); }
    void add(int i, T v){ for(; i<=n; i+=i&-i) bit[i]+=v; }
    T sumPrefix(int i) const { T r{}; for(; i>0; i-=i&-i) r+=bit[i]; return r; }
    T sumRange(int l,int r) const { if(r<l) return T{}; return sumPrefix(r)-sumPrefix(l-1); }
};

// -------------------- DSU (Union-Find) --------------------
struct DSU {
    int n; vector<int> p, sz;
    DSU(int n=0){ init(n); }
    void init(int n_){ n=n_; p.resize(n); iota(all(p),0); sz.assign(n,1); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b]; return true;
    }
};

// -------------------- Generic Segment Tree (Monoid) --------------------
template<typename T, class F>
struct SegTree {
    int n; T id; F f; vector<T> st;
    SegTree(int n=0, T id=T(), F f=F()): n(0), id(id), f(f) { if(n) init(n); }
    void init(int n_){ n=1; while(n<n_) n<<=1; st.assign(2*n, id); }
    void build(const vector<T>& a){
        init(sz(a));
        for(int i=0;i<sz(a);++i) st[n+i]=a[i];
        for(int i=n-1;i;--i) st[i]=f(st[i<<1], st[i<<1|1]);
    }
    void setPoint(int i, T v){
        i+=n; st[i]=v; for(i>>=1;i;i>>=1) st[i]=f(st[i<<1], st[i<<1|1]);
    }
    T query(int l,int r){ // inclusive l,r
        T L=id, R=id; for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
            if(l&1) L=f(L, st[l++]);
            if(!(r&1)) R=f(st[r--], R);
        } return f(L,R);
    }
};
// Example: SegTree<int, function<int(int,int)>> st(n, 0, [](int a,int b){return max(a,b);});

// -------------------- Graph Utils --------------------
vector<int> bfs_levels(const vector<vector<int>>& g, int s){
    int n=sz(g); vector<int> d(n, -1); queue<int> q; d[s]=0; q.push(s);
    while(!q.empty()){
        int v=q.front(); q.pop();
        for(int to: g[v]) if(d[to]==-1){ d[to]=d[v]+1; q.push(to); }
    }
    return d;
}

vector<ll> dijkstra(const vector<vector<pair<int,int>>>& g, int s){
    int n=sz(g); vector<ll> d(n, INF64);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    d[s]=0; pq.push({0,s});
    while(!pq.empty()){
        auto [dv,v]=pq.top(); pq.pop(); if(dv!=d[v]) continue;
        for(auto [to,w]: g[v]){
            if(d[v]+w < d[to]){
                d[to]=d[v]+w; pq.push({d[to], to});
            }
        }
    }
    return d;
}

// -------------------- Sieve (primes) --------------------
vector<int> primes_upto(int n){
    vector<int> pr, lp(n+1);
    for(int i=2;i<=n;i++){
        if(lp[i]==0){ lp[i]=i; pr.push_back(i); }
        for(int p: pr){
            ll x=1LL*p*i; if(p>lp[i] || x>n) break;
            lp[x]=p;
        }
    }
    return pr;
}

// -------------------- Coordinate Compression --------------------
template<class T>
struct Compressor {
    vector<T> vals;
    void add(const T& x){ vals.push_back(x); }
    void build(){ sort(all(vals)); vals.erase(unique(all(vals)), vals.end()); }
    int get(const T& x) const { return (int)(lower_bound(all(vals), x)-vals.begin()); } // 0-index
    int size() const { return (int)vals.size(); }
};

// -------------------- Directions --------------------
const int DX4[4]={1,0,-1,0}, DY4[4]={0,1,0,-1};
const int DX8[8]={1,1,0,-1,-1,-1,0,1}, DY8[8]={0,1,1,1,0,-1,-1,-1};

// -------------------- Y-Combinator (recursive lambdas) --------------------
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class... Args> decltype(auto) operator()(Args &&...args){
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun){
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

// -------------------- I/O helpers --------------------
template<class T> istream& operator>>(istream& in, vector<T>& a){ for(auto &x:a) in>>x; return in; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& a){
    for(int i=0;i<sz(a);++i){ if(i) out<<' '; out<<a[i]; } return out;
}

bool dfs(int u, int p , vector<vector<ll>>& adj, vector<bool>& vis,int& count,vector<ll>& deg)
{
    vis[u] = true;
    if(deg[u] > 1) count ++;
    for(auto v : adj[u])
    {
        if(v!=p)
        {  
            if(vis[v])
            return false;
            else if(!dfs(v,u,adj,vis,count,deg))
            return false;
        }
    }
    return true;
}




// =================================================================
//  Solve function: put your problem logic here
// =================================================================
void solve(){
    // Example: read n, array, do something
    // int n; cin>>n; vector<ll> a(n); cin>>a; cout<<accumulate(all(a), 0LL)<<"\n";
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    vector<bool> vis(n+1 , false);
    vector<ll> deg(n+1 , 0);
    for(int i = 0 ; i < m ;i ++)
    {
        int u,v;
        cin >> u;
        cin >> v;
        deg[v]++;
        deg[u]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int u = 1 ; u <= n ; u ++)
    {
        int cnt = 0;
        for(auto v : adj[u])
        {
            if(deg[v] > 1) cnt++;
        }
        if(cnt > 2)
        {
            cout << 0 << endl;
            return;
        }
    }
    int comp = 0;
    int acc = 1;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(!vis[i])
        {
            comp++;
            int count = 0;
            if(!dfs(i,0,adj,vis,count,deg))
            {
                cout << 0 << endl;
                return;
            }
            if(count >= 2) acc = (acc * 2)%MOD;
        }
    }
    vector<int> tmp(n+1,0);
    for(int i = 1 ; i <= n ; i ++)
    {
        for(auto v : adj[i])
        {
            if(deg[v] == 1)
            {
                tmp[i]++;
            }
        }
    }
    vector<ll> fact(n+1, 1);
    for(int i = 2; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    ll ans = fact[comp];
    for(auto val : tmp)
    {
        ans = (ans * fact[val]) % MOD;
    }
    ans = (ans * 2) % MOD;
    
    cout << (ans * acc) % MOD << endl;
}

// =================================================================
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute (edit the limit to your needs):
    // comb.init(1'000'000);

    const bool MULTI_TESTS = true; // set false if single test case
    int T = 1;
    if (MULTI_TESTS) cin >> T;
    while (T--) solve();
    return 0;
}
