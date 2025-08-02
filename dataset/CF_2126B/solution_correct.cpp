    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace std;
    using namespace __gnu_pbds;
    using namespace chrono;
     
    typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    // order_of_key(k) : no. of elements < k
    // *find_by_order(i) : value at index i (0-based)
    typedef pair<int, int> pii;
    typedef pair<long long, long long> pll;
    typedef vector<int> vi;
    typedef vector<long long> vl;
    typedef vector<string> vs;
    typedef vector<char> vc;
    typedef vector<vc> vvc;
    typedef vector<vi> vvi;
    typedef vector<vl> vvl;
    typedef vector<pii> vpii;
    typedef vector<pll> vpll;
    typedef map<int,int> mii;
    typedef map<long long, long long> mll;
    typedef set<int> si;
    typedef set<long long> sl;
    typedef priority_queue<int,vector<int>,greater<int>> pqi;
    typedef priority_queue<long long,vector<long long>,greater<long long>> pql;
    typedef priority_queue<pii,vector<pii>,greater<pii>> pqpii;
    typedef priority_queue<pll,vector<pll>,greater<pll>> pqpll;
    typedef priority_queue<vi,vector<vi>,greater<vi>> pqvi;
    typedef priority_queue<vl,vector<vl>,greater<vl>> pqvl;
     
     
    #define ll long long
    #define lld long long double
    #define s(x) (int) (x).size()
    #define all(x) (x).begin(),(x).end()
    #define traverse_vec(x) for(auto i : x) { cout << i <<" ";}nl;
    #define traverse_map(x) for(auto p : x) {cout << p.first << " : "<< p.second<<endl;};
    #define traverse_mat(x) for(int i=0; i<x.size(); i++){ for(int j=0; j<x[0].size(); j++) { cout<<x[i][j]<<" ";}nl;}
    #define take_mat(x) for(int i=0; i<x.size(); i++){ for(int j=0; j<x[0].size(); j++) { cin>>x[i][j];}}
    #define take_vec(x) for(auto i=0; i<x.size(); i++) {cin>>x[i];}
    #define nl (cout << endl)
    #define yes (cout<<"YES"<<endl)
    #define no (cout<<"NO"<<endl)
    #define impossible (cout<<"IMPOSSIBLE"<<endl)
    #define rep(i,a,b) for(int i = a; i < b; i++)
    #define repr(i,a,b) for(int i = a; i >= b; i--)
    #define mp(x,y) (make_pair(x,y))
    #define pb push_back
    #define ff first
    #define ss second
    #define dbg(x) cout << #x << " = " << x << "\n"
    #define startTimePoint chrono::steady_clock::now()
     
    /*###########################################################################################################*/
    ll mod = 1e9 + 7;
    int del4r[] = {0, 1, 0, -1};
    int del4c[] = {-1, 0, 1, 0};
    int del8r[] = {0, 1, 0, -1, 1, 1, -1, -1};
    int del8c[] = {-1, 0, 1, 0, -1, 1, 1, -1};
     
    vl fact;
    vector<bool> sieve;
     
    ll ceilii(ll x, ll y){ return (x + y - 1)/y;}
    template <typename T = int>
    int setbits(T x) { return __builtin_popcount(x); }
    void get_factorial(ll n, ll p = mod){
      fact.resize(n+1); fact[0] = 1;
      for(int i=1; i<=n; i++) fact[i] = (fact[i-1]*i)%p;
      return;
    }
    void get_sieve(int N = 9000000){
      sieve.resize(N+1);
      sieve[0] = false;
      sieve[1] = false;
      for(int i = 2;i<=N; i++) sieve[i] = true;
      for(int i=2; i*i<=N; i++){if(sieve[i] == true) for(int j=i*i; j<=N; j+=i) sieve[j] = false;}
    }
    vl getPrefixSum(vl a){
      vl prefixSum(s(a)); prefixSum[0] = a[0];
      for(int i=1; i<s(a); i++) prefixSum[i] = prefixSum[i-1] + a[i];
      return prefixSum;
    }
    vl getSuffixSum(vl a){
      vl suffixSum(s(a)); suffixSum[s(a)-1] = a[s(a)-1];
      for(int i=s(a)-2; i>=0; i--) suffixSum[i] = suffixSum[i+1] + a[i];
      return suffixSum;
    }
    ll exp(ll x, ll y, ll p = LLONG_MAX) {
        ll res = 1; x = x % p;  
        while (y > 0) {    
            if (y & 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    ll modInverse(ll n, ll p) { return exp(n, p - 2, p);}
    ll nCrFermat(ll n, ll r, ll p = mod) {
        if (n < r) return 0;
        if (r == 0) return 1;
        return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
    }
    double getTime(const steady_clock::time_point& start) {
      return duration_cast<duration<double>>(steady_clock::now() - start).count();
    }
    /*###########################################################################################################*/

    ll sol(int i,vl &b,int k,vl &a)
    {
        
        if(i>=b.size()){return 0;}
        if(a[i]!=-1){return a[i];}
        ll ans=0;
        if(b[i]>=k)
        {
            ans=max(1+sol(i+k+1,b,k,a),sol(i+1,b,k,a));
        }
        else{
            ans=sol(i+1,b,k,a);
        }
        return a[i]=ans;
    }


    void solve(){
      int n,k;
      cin>>n>>k;
      vl a(n);take_vec(a);
      vl b(n);
      for(int i=n-1;i>=0;i--)
      {
        if(i==n-1){if(a[i]==0){b[i]=1;}}
        else if(a[i]==0){b[i]=b[i+1]+1;}
      }
      vector<ll>aa(n,-1);
      cout<<sol(0,b,k,aa)<<endl;

    }
     
    int main() {
    //   ios_base::sync_with_stdio(false);
    //   cin.tie(nullptr);
      
    //   #ifndef ONLINE_JUDGE
    //   freopen("VSINPUT.txt", "r", stdin);
    //   freopen("VSOUTPUT.txt", "w", stdout);
    //   #endif
     
      int t;
      cin>>t;
    //   auto start = startTimePoint;
      while (t--) {
        solve();
      }
     
      // cout << fixed << setprecision(10) << endl<<"Time taken: " << getTime(start) << " seconds" << endl;
      return 0;
    }