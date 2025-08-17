#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll  int
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pair<ll, ll>> vii;
typedef pair<ll, ll> ii;
typedef map<ll, ll> mii;
#define sz(C) return (int)C.size()
#define ld long double
#define all(c) c.begin(), c.end()
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pb push_back
#define se second
#define fi first
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())
#define inf 2e15
#define MAX 500005
#define MAX1 5002
#define MOD2 1000000007
#define MAXLEN 1000010
#define MOD1 998244353
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ii, null_type, less_equal<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_ii;
template <ll MOD = 998'244'353>
struct mint
{
  ll value;
  static const ll MOD_value = MOD;

  mint(long long v = 0)
  {
    value = v % MOD;
    if (value < 0)
      value += MOD;
  }
  mint(long long a, long long b) : value(0)
  {
    *this += a;
    *this /= b;
  }

  mint &operator+=(mint const &b)
  {
    value += b.value;
    if (value >= MOD)
      value -= MOD;
    return *this;
  }
  mint &operator-=(mint const &b)
  {
    value -= b.value;
    if (value < 0)
      value += MOD;
    return *this;
  }
  mint &operator*=(mint const &b)
  {
    value = (long long)value * b.value % MOD;
    return *this;
  }

  friend mint mexp(mint a, long long e)
  {
    mint res = 1;
    while (e)
    {
      if (e & 1)
        res *= a;
      a *= a;
      e >>= 1;
    }
    return res;
  }
  friend mint inverse(mint a) { return mexp(a, MOD - 2); }

  mint &operator/=(mint const &b) { return *this *= inverse(b); }
  friend mint operator+(mint a, mint const b) { return a += b; }
  friend mint operator-(mint a, mint const b) { return a -= b; }
  friend mint operator-(mint const a) { return 0 - a; }
  friend mint operator*(mint a, mint const b) { return a *= b; }
  friend mint operator/(mint a, mint const b) { return a /= b; }
  friend std::ostream &operator<<(std::ostream &os, mint const &a) { return os << a.value; }
  friend bool operator==(mint const &a, mint const &b) { return a.value == b.value; }
  friend bool operator!=(mint const &a, mint const &b) { return a.value != b.value; }
};



void solve(){
    ll n,m;
    cin >> n >> m;
    set<ll> s;
    ll sums = 0;
    if(m > ((n * (n+1)) / 2) or (m < n)) {
      cout << -1 << endl;
      return;
    }
    for(ll i = n;i>0;i--){
      
       ll z = i + sums;
       ll left = i - 1;
       if(z + left < m) s.insert(i);
       else{
        ll p = m - sums - i;
        if(p > 0) s.insert(p + 1);
        break;
       }
       sums += i;
    }
    ll root = 1;
    if(s.size()){
    auto it = s.begin();
    auto it1 = it; it1++;
    root = *(s.rbegin());
    cout << root << endl;
    while(it1 != s.end()){
      cout << *it << " " << *it1 << endl;
      it = it1;
      it1++;
    }
   
    cout << *(s.begin()) << " " << 1 << endl;
    }
    else cout << root << endl;
    for(ll i = 2;i<=n;i++){
      if(s.find(i) == s.end()){
        cout << 1 << " " << i << endl;
      }
    }
    cout << endl;
  }

  
  
void preprocess() {
  
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("ou27.txt", "w", stdout);
  #endif
  ll t;
  ll p = 0;
  t = 1;
  preprocess();
  cin >> t;
  while (p < t)
  {
    // cout << p << endl;
    //  cout << "Case " << p + 1 << ": ";
    // if(p == 6 and t == 10){
    //   ll n,k;
    //   cin >> n;
    //   vi a(n-1);
    //   vi b(n);
    //   for (ll i = 0; i < n - 1; i++)
    //   {
    //     cin >> a[i];
    //   }
    //   for(ll i = 0;i<n;i++) cin >> b[i];
    //   // print the input with : delim
    //   cout << n << ":";
    //   for (ll i = 0; i < n-1; i++)
    //   {
    //     cout << a[i] << ":";
    //   }
    //   for(ll i = 0;i<n;i++) cout << b[i] << ":";
    //   cout << endl;
    //   return 0;
    // }
    solve();
    p++;
  }
  cerr << "Time:" << 1000 * ((float)clock()) / (float)CLOCKS_PER_SEC << "ms\n";
}