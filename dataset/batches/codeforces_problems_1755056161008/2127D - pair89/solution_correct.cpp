//Abhinav garg


#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int                 long long int
#define ld                 long double
#define fps(x,y)           fixed << setprecision(y) << x
#define loop(i,a,n)        for(int i=a;i<=n;i++)
#define set_bits           __builtin_popcountll
#define sz(x)              ((int)(x).size())
#define rev(j,a,n)         for(int j=a;j>=n;j--)
#define it(i,v)            for(auto i=v.begin();i!=v.end();i++)
#define pb                 push_back
#define vi                 vector
#define all(v)             v.begin(),v.end()
#define pr                 pair<int, int>
#define ff                 first
#define ss                 second
#define ump                unordered_map
#define ordered_set tree<pr, null_type,less<pr>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;


const int mod=1000000007;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif


void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned int t) {cerr << t;}
void _print(bool t) {cerr << t;}


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


inline void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   #ifndef ONLINE_JUDGE
   freopen("inp.txt", "r", stdin);
   freopen("op.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
   #endif
}


void printVector(vi<int> &v) {
    for (auto x:v) {
        cout<<x<<' ';
    }
    cout<<endl;
}

vi<int> fact;

void test(){
    int n,m; cin>>n>>m;
    vi<vi<int>> tr(n);
    loop(i,0,m-1) {
        int a,b; cin>>a>>b;
        a--, b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    if(m != n-1) {
        cout<<0<<"\n";
        return;
    }

    #define deg(v) tr[v].size()

    vi<vi<int>> ntr(n);
    int cnt = 0;

    loop(i,0,n-1) {
        if(deg(i) == 1) continue;
        cnt++;
        for(auto x: tr[i]) {
            if(deg(x) > 1) {
                ntr[i].push_back(x);
            }
        }
    }

    loop(i,0,n-1) {
        if(ntr[i].size() > 2) {
            cout<<0<<"\n";
            return;
        }
    }

    int ans;

    if(cnt >= 2) {
        ans = 4;
    } else {
        ans = 2;
    }

    loop(i,0,n-1) {
        int a = deg(i)-ntr[i].size();
        (ans *= fact[a])%=mod;
    }

    cout<<ans<<"\n";

}


int32_t main(int32_t argc,char const *arg[]){
    fastio();
    int tc=1;
    fact.resize(200001);
    fact[0] = 1;
    loop(i,1,200000) {
        (fact[i] = fact[i-1] * i)%=mod;
    }
    //prime();
    cin>>tc;
    while(tc--){
        test();
    }


    return 0;
}
/* if (a|b)+(a&b) = (a+b)*/