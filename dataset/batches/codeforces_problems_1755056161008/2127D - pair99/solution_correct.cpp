#include<bits/stdc++.h> 
using namespace std;

#define endl '\n'
const int mo=998244353;
#define ll long long
#define ull unsigned long long
#define lld long double
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define mxn 400005
//#define for((int i=0);i<n;i++) for(i,n)
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
// const int N= 1e5+5;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


const int INF = int(1e9) + 5;
#define ll long long 

#define int long long


const int MOD = 1e9+7;

const int N = 2e5+5;

vector<int> factorial(N+1);
vector<int> inverse_factorial(N+1);

ll add(ll x, ll y)
    {
        x += y;
        // while(x >= MOD)
        //     x -= MOD;
        // if below lines don't work uncomment above two lines
        if(x>=MOD){
            return x%MOD;
        }
        // while(x < 0)
        //     x += MOD;
        // if below lines don't work uncomment the above two lines
          if(x<0){
            ll diff=  -x;
            if(diff%MOD==0){
                return (ll)0;
            }
            return MOD-diff%MOD;
        }
        return x;                         
    }

ll sub(ll x, ll y)
    {
        return add(x, MOD - y);
    }

ll mul(ll x, ll y)
    {
        return ((x%MOD) * 1ll * (y%MOD)) % MOD;
    }

ll binpow(ll x, ll y)
    {
        ll res = 1;
    while (y > 0) {
        if (y & 1)
        res = mul(res, x);
        x = mul(x, x);
        y >>= 1;
    }
    return res;
    }

ll inv(ll x)
    {
        return binpow(x, MOD - 2);   
    }

ll divide(ll x, ll y)
    {
        return mul(x, inv(y));
    }

    ll getnCr(ll n, ll r){
        return mul(factorial[n], mul(inverse_factorial[r], inverse_factorial[n-r]));
    }

void precal(){
    factorial[0] = 1;
   for (int i = 1; i <= N; i++) {
    factorial[i] = mul(factorial[i - 1], i);
    }

    for(int i = 0; i <= N; i++){
        inverse_factorial[i] = inv(factorial[i]);
    }

}

bool dfs1(int node, int parent, vector<vector<int>> &adj, 
     vector<int> &visited){

     visited[node] = 1;
     for(auto c: adj[node]){
          if(c!=parent){
               if(visited[c]){
                    return true;
               }
               if(dfs1(c, node, adj, visited)){
                    return true;
               }
          }
     }

     return false;


}


bool dfs2(int node, int parent, vector<vector<int>> &adj, vector<int> &visited, 
    vector<vector<int>> &childrens){
    visited[node] = 1;
    bool current = false;
    for(auto c: adj[node]){
        if(c!=parent){
            current = true;
            bool val = dfs2(c, node, adj, visited, childrens);
            if(val){
                childrens[node].push_back(c);
            }
        }
    }


    return current;


}


int solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++, degree[v]++;
    }

    debug(adj);


    

    vector<int> visited(n, 0);
    vector<vector<int>> childrens(n, vector<int> ());

    if(dfs1(0, -1, adj, visited)){
        return 0;
    }

    visited.assign(n, 0);
    dfs2(0, -1, adj, visited, childrens);

    debug(childrens);

    int cnt = 0;

    if((int)childrens[0].size()>2){
        return 0;
    }


     if((int)childrens[0].size()==0){
        return mul(2, factorial[degree[0]]);
    }

    
    queue<int> q;

    if((int)childrens[0].size()==1){
        if((int)childrens[childrens[0][0]].size()>2){
            return 0;
        }
        if((int)childrens[childrens[0][0]].size()==2){
            if(degree[0]!=1){
                return 0;
            }
        }
        for(auto c: childrens[childrens[0][0]]){
            q.push(c);
        }
    }
    else
    for(auto c: childrens[0]){
        q.push(c);
    }

    bool possible = true;



    while(!q.empty()){
        if((int)childrens[q.front()].size()>1){
            possible = false;
            break;
        }
        if((int)childrens[q.front()].size()>0)
        q.push(childrens[q.front()][0]);
        q.pop();
    }

    if(!possible){
        return 0;
    }



    auto getAns = [&](int startNode){
        int tmpans = 1;
        while((int)childrens[startNode].size()!=0){
            tmpans = mul(tmpans, factorial[degree[startNode] - 2]);
            startNode = childrens[startNode].back();
        }
        tmpans = mul(tmpans, factorial[degree[startNode] - 1]);
        return tmpans;
    };


    int finans = 2;

    if((int)childrens[0].size()==1){
        finans = mul(finans, factorial[degree[0] - 1]);
        if(degree[0]>1){
            finans = mul(finans, 2);
        }

        if((int)childrens[childrens[0][0]].size()==0){
            int tmp;
            if(degree[0]==1){
                tmp = factorial[degree[childrens[0][0]]];
            }
            else{
                tmp = factorial[degree[childrens[0][0]] - 1];
            }
            finans = mul(finans, tmp);
            return finans;
        }

        if((int)childrens[childrens[0][0]].size()==1){
            if(degree[0]==1){
                finans = mul(finans, 2);
                finans = mul(finans, factorial[degree[childrens[0][0]] - 1]);
            }
            else{
                finans = mul(finans, factorial[degree[childrens[0][0]] - 2]);
            }
            finans = mul(finans, getAns(childrens[childrens[0][0]][0]));
            return finans;
        }

        assert((int)childrens[childrens[0][0]].size()==2);
        assert(degree[0]==1);

        // debug("came here");

         finans = mul(finans, 2);
            finans = mul(finans, factorial[degree[childrens[0][0]] - 2]);
            finans = mul(finans, getAns(childrens[childrens[0][0]][0]));
            finans = mul(finans, getAns(childrens[childrens[0][0]][1]));
            return finans;
    }


    assert((int)childrens[0].size()==2);
        finans = mul(finans, factorial[degree[0] - 2]);
        finans = mul(finans, 2);
        finans = mul(finans, getAns(childrens[0][0]));
        finans = mul(finans, getAns(childrens[0][1]));
        return finans;




}




int32_t main() {
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
   #endif
   int t;
   cin>>t;
   precal();
   while(t--){
    cout<<solve()<<endl;
    


   }
   
   }