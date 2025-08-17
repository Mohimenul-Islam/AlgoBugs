#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
 
 
#ifndef ONLINE_JUDGE 
#include "template.cpp"
#else
  #define debug(...) 
  #define debugArr(...)
#endif
 
#define Tct   template<typename T>
#define Tctu  template<typename T,typename U>
#define clr(cnt, x) memset((cnt), (x), sizeof(cnt))
typedef long long ll;
Tct using V=vector<T>;
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define bg(cn) cn.begin()
#define ff first
#define bk(x) x.back() 
#define fk(x) x.fornt()
#define eb emplace_back
#define ss second 
#define pb push_back
 
template<class Fun> 
class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
#define SFINAE(x, ...)                                                         \
    template <class, class = void> struct x : std::false_type {};              \
    template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}
  SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));SFINAE(IsTuple, typename std::tuple_size<T>::type);SFINAE(Iterable, decltype(std::begin(std::declval<T>())));
  template <auto &is> struct Reader {template <class T> void Impl(T &t) {if constexpr (DefaultI<T>::value) is >> t;else if constexpr (Iterable<T>::value) {for (auto &x : t) Impl(x);} else if constexpr (IsTuple<T>::value) {std::apply([this](auto &...args) { (Impl(args), ...); }, t);} else static_assert(IsTuple<T>::value, "No matching type for read");}template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }};
  template <class... Ts> void re(Ts &...ts) { Reader<cin>{}.read(ts...); }
#define def(t, args...)t args;re(args);
template <auto &os> struct Writer {template <class T> void Impl(const T &t) const {if constexpr (DefaultO<T>::value)os << t;else if constexpr (Iterable<T>::value) {bool first = true;for (const auto &x : t) {if (!first) os << ' ';Impl(x);first = false;}
} else {static_assert(DefaultO<T>::value || Iterable<T>::value, "No matching type for print");}
}template <class... Ts> void print(const Ts &...ts) const {((Impl(ts), os << ' '), ...);os << '\n';}};
template <class... Ts> void pr(const Ts &...ts) {Writer<cout>{}.print(ts...);}
 

Tct void remDup(vector<T> &v){sort(all(v)); v.erase(unique(all(v)),end(v));}
Tctu void safeErase(T &t, const U &u) {auto it = t.find(u);assert(it != end(t)); t.erase(it);}
Tct int lwb(const V<T>&a,const T&b){return int(lb(all(a), b)-bg(a));}// (v[r]>=x && v[l]<x) return r;
Tct int upb(const V<T>&a,const T&b){return int(ub(all(a),b)-bg(a));}//( v[r]>x && v[l]<=x) return r;
Tctu int CC(const T&a,const U&b){return int(count(all(a),b));}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
inline ll getrandom(ll a,ll b) { return uniform_int_distribution<ll>(a,b)(rng); }
 
void YN(bool x){if(x)cout<<"YES\n";else cout<<"NO\n";}
ll SUM_(ll n){return (n*(n+1))/2;}
ll SUM_(ll a,ll b) { return (b- a+1) * (a + b) / 2;}
ll A_SUM(ll n,ll a,ll b){return (n*(a+b))/2;}
ll G_SUM(ll k,ll a,ll b){return ((b*k)-a)/(k-1);}
ll cdiv(ll a, ll b) {return a / b + ((a ^ b) > 0 && a % b);} 
Tctu bool cmax(T &a, U b){return (a<b?a=b,1:0 );}
Tctu bool cmin(T &a, U b){return (a>b?a=b,1:0 );}
const ll inf = 2e18;
#define PQ priority_queue
Tct using  PQ1 =PQ<T,V<T>,greater<T>>;
 
#define to_str(x) (to_string(x)) 
#define to_ll(x) (stoll(x))
#define to_char(x) ((x)+'0')
#define to_int(x) ((x)-'0')
 
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};  
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};  
 
constexpr int Pct(ll x){return __builtin_popcountll(x);}  
constexpr int Msb(ll x){return int(log2(x));}  
constexpr ll P2(ll x) { return 1ll << x; }
constexpr ll Msk2(ll x) { return P2(x) - 1;}
constexpr ll Lsb(ll x) { return  x&~(x-1);}
constexpr  bool Is_set(ll x,ll j) { return  (x&(1ll<<j) )==(1ll<<j);}
 
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef V<pll> vll;
typedef V<pii >vii;
typedef V<V<int> > vvi;
typedef vector<ll>vl;  
typedef V<vl>vvl;
#define sz(n) int((n).size()) 
#define fora(cn) for(auto &x : (cn))
using   u_128 = unsigned __int128;
using   i_128=__int128_t;
#define PI 2*acos(0) 
#define el '\n'
typedef unsigned long long ull;
typedef vector<int> vi;
#define se(X) setprecision(X)
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,r) for(int (i)=(0);(i)<(r);(i)++)
#define rep1(i,l,r) for(int (i)=(l);(i)<(r);(i)++)
#define repr(i,r,l) for(int (i)=(r);(i)>=(l);(i)--)
const int MX=100005;






void solve(){

   
    int n;cin >> n; 
    vector<int> a(n) ;
    rep(i,n)cin >>a[i] ;
    ll ans=0 ;
    vector<int> dp(n);
    dp[0]=1 ;
    if(a[1]<a[0]){
         dp[1]=3;
    }else dp[1]=2; 
     
    for(int i=2;i<n;i++){
         if(a[i]<a[i-1]){
            dp[i]=i+1+dp[i-1];
         }else { 
            dp[i]=dp[i-1]+1 ;
         }
    }
 
   rep(i,n)ans+=dp[i] ;
  cout<<ans<<el ;
}
int main() {
 ios::sync_with_stdio(false);cin.tie(nullptr);
 int tt=1;
  cin>>tt;
  while(tt--){
    solve();
  }
 return 0;
}   
 

