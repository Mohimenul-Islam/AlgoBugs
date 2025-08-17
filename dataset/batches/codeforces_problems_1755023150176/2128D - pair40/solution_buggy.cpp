#include <bits/stdc++.h>
    using namespace std;
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define sortall(x) sort(all(x))
    #define sortrall(x) sort(rall(x))
    #define ff first
    #define ll long long 
    #define ppb pop_back
    #define pb push_back
    #define ss second
    #define PI 3.141592653589793238462
    #define fl(i,n) for(int i=0;i<n;i++)
    #define rl(i,m,n) for(int i=m;i>=n;i--)
    #define rep(m,n) for(int i=m;i<n;i++)
    #define py cout<<"YES\n";
    #define pm cout<<"-1\n";
    #define pn cout<<"NO\n";
    #define code ios_base::sync_with_stdio(false);
    #define by cin.tie(NULL);
    #define krish cout.tie(NULL);
    #define Krish_gujarati
    
    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef vector<vi> vvi;
    typedef vector<vl> vvl;
    typedef vector<pii> vii;
    typedef vector<pll> vll;
    typedef double dd;
    typedef unsigned long long ull;
    typedef long double lld;
     
    #ifdef Krish_gujarati
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
    #else
    #define debug(x);
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
     
     
    // Operator overloads
    template<typename T1, typename T2> // cin >> pair<T1, T2>
    istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
    template<typename T> // cin >> vector<T>
    istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
    template<typename T1, typename T2> // cout << pair<T1, T2>
    ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
    template<typename T> // cout << vector<T>
    ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
     
    // Mathematical functions
    ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
    ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
    ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
    ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
     
    //checks
    bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
    bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
    bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
     
    //Sorting
    bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
    bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
    const int md= 998244353;
   
    void solve()
    { 
      int n;
      cin>>n;
      vector<int> v(n);
      cin>>v;
      vector<int>dp (n,0);
      dp[0]=1;
      ll sum=1;
      for(int i=1;i<n;i++)
      {
        if(v[i-1]>v[i])
        {
            dp[i]=dp[i-1]+(i+1);
        }
        else
        {
            dp[i]=dp[i-1]+1;
        }
        sum+=dp[i]*1LL;
      }
      cout<<sum<<endl;
    }   
    int main()
    {   
        code by krish
        
        int t;
        t=1;
        cin>>t;
        while(t--)
        {
            solve();
     
        }
     
        
        return 0;
    }