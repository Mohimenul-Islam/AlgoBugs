//Bismillah

#include<bits/stdc++.h>
using namespace std;

#define int long long 
typedef long long ll;

#define PB push_back
#define F first
#define S second
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mx_int_prime 999999937

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 1e9+100;
const ll infLL = 4e18;
#define MOD 1000000007

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

 
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}
 
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}
 
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
 
template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
 
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}
 
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
 
void faltu () {
            cerr << endl;
}
 
template <typename T>
void faltu( T a[], int n ) {
            for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                cerr << endl;
}
 
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
            cerr << arg << ' ';
                faltu(rest...);
}
 
const int N=2e5+1;
std::vector<int> adj[N];
int vis[N];
map<pair<int,int>,bool>mp;
int dfs(int u,int clr)
{
    vis[u]=clr;
    int one=0;
    int more=0;
    int cur=1;
    for(auto &v: adj[u]){
        if(vis[v]==clr){
            return 0;
        }else{
            if(vis[v]!=(3-clr)){
                mp[{min(u,v),max(u,v)}]=1;
                cur*=dfs(v,3-clr);
                cur%=MOD;
                if(adj[v].size()==1){ 
                    one++;
                    cur*=one;
                    cur%=MOD;
                }
                else more++;
            }else {
                if(mp.find({min(u,v),max(u,v)})==mp.end())   return 0;//connected to earlier with new edge...
            }
        }
    }
    if(more>2){
        return 0;
    }else return cur;
}   
int solve(int n)
{
    bool isMoreThanOne=0;
    int ans=0,cnt=0,pos=1;
    for(int i=1;i<=n;i++){
        if(adj[i].size()>1){
            cnt++;
            pos=i;
        }
    }
    ans=dfs(pos,1);
    if(cnt>1) ans=(ans*2)%MOD;
    ans*=2;//side change
    ans%=MOD;

    return ans;
}
signed main()
{
    optimize();
    #ifndef ONLINE_JUDGE
    file();
    #endif

    int t,n,m,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        mp.clear();
        for(int i=1;i<=n;i++){
            adj[i].clear();
            vis[i]=0;
        }
        for(int i=1;i<=m;i++) {
            cin>>u>>v;
            adj[u].PB(v);
            adj[v].PB(u);
        }

        cout<<solve(n)<<endl;
    }

    return 0;
}
    