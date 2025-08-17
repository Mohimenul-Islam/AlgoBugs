#include <bits/stdc++.h>
using namespace std;

/* Code By -Aryan 
   Gaming_name-@13kaatdungi(Valorant,BGMI etc)
   Moto- "The eyes chico....they never lie ;)"
*/
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define per(i,a,b) for(int i = a; i >= b; --i)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 1e9;
const ll LINF = 1e18;

ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m + b % m) % m + m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m - b % m) % m + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m * b % m) % m; }
ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll m = MOD) { return mod_pow(a, m - 2, m); }

template<typename T> void read(vector<T>& v) { for (auto &x : v) cin >> x; }
template<typename T> void print(const vector<T>& v) { for (auto x : v) cout << x << ' '; cout << endl; }

//DSU
class DSU{
    vector<int>rank,par,size;
    public:
    DSU(int n){//constructor for assigning inital stages of rank and par
        rank.resize(n+1,0);
        par.resize(n+1,0);
        size.resize(n+1,0);
        for (int  i = 0; i <=n; i++)
        {
            par[i]=i;//initially all nodes are thought to be independent so par of that particular node is the node itself 
            size[i]=1;//all nodes independently have size=1;
        }
    }
    int findUltPar(int node){
        if(node==par[node]){//if at the point node itself becomes its par i.e at its end point!!
            return node;
        }
        return par[node]=findUltPar(par[node]);//compressing path algo if 1->4->7 ;then 1->7 simple means this
    }
    bool unionByRank(int u,int v){//function formaking updation changes in par and rank vectors 
        int ult_u=findUltPar(u);
        int ult_v=findUltPar(v);
        if(ult_u==ult_v)return false;//that is they are in same graph
        if(rank[ult_u]>rank[ult_v]){
            par[ult_v]=ult_u;
        }else if(rank[ult_u]<rank[ult_v]){
            par[ult_u]=ult_v;
        }else{//if they equal
            rank[ult_u]++;
            par[ult_v]=ult_u;
        }
        return true;
    }
    void unionBySize(int u,int v){//function formaking updation changes in par and rank vectors 
        int ult_u=findUltPar(u);
        int ult_v=findUltPar(v);
        if(ult_u==ult_v)return;//that is they are in same graph
        if(size[ult_u]<size[ult_v]){
            size[ult_v]+=size[ult_u];
            par[ult_u]=ult_v;
        }else{//if they equal
            size[ult_u]+=size[ult_v];
            par[ult_v]=ult_u;
        }
    }
};

//Segment tree
const int N = 1e5+5;
int a[N], seg[4*N];

// Build Function
void build(int ind, int low, int high, function<int(int, int)> op) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2*ind+1, low, mid, op);
    build(2*ind+2, mid+1, high, op);
    seg[ind] = op(seg[2*ind+1], seg[2*ind+2]);
}

// Query Function
int query(int ind, int low, int high, int l, int r, function<int(int, int)> op, int identity) {
    if (low > r || high < l) return identity;
    if (low >= l && high <= r) return seg[ind];
    int mid = (low + high) / 2;
    int left = query(2*ind+1, low, mid, l, r, op, identity);
    int right = query(2*ind+2, mid+1, high, l, r, op, identity);
    return op(left, right);
}


vector<ll>fact;

void pre(int n) {
    fact.resize(n+1);
    fact[0]=1;
    for (int i=1;i<= n;i++) {
        fact[i]=(fact[i-1]*i)%MOD;
    }
}



void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }
    ll ans=2;
    int trt=0;

    if(m>=n)ans=0;
    rep(i,1,n+1){
        if(adj[i].size()>1){
            int ctr=0;
            for(auto x:adj[i]){
                if(adj[x].size()==1){
                    ctr++;
                }
            }
            if(ctr>=adj[i].size()-2)ans*=(fact[ctr])%=MOD;
            else ans=0;
        }else trt++;
    }
    if(trt<n-1)trt=2;
    else trt=1;
    cout<<(ans*trt%MOD)<<endl;
}


int main() {
    fast_io;
    int t = 1;
    
    pre(2e5+5);
    cin >> t;
    while (t--) solve();
    return 0;
}