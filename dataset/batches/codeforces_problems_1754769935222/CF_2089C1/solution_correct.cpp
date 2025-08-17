#include "bits/stdc++.h"
#ifdef AlRntn
#include "debug.hpp"
#else
#define debug(...) void(0)
#define tstr(...) void(0)
#endif
using int64 = int64_t;
using uint64 = uint64_t;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define fi first
#define se second
#define sz(x) int64_t(x.size())
#define all(x) x.begin(), x.end()
#define spc ' '
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ever ;1;
constexpr int64_t inf = 1e18 + 100;
constexpr int64_t mod1 = 1e9+7;
constexpr int64_t mod2 = 998244353;
constexpr int64_t mod3 = 1e9+9;
constexpr int64_t mod4 = (1ll<<31) - 1;
constexpr long double PI = 2*asinl(1.0);
int dx[4] = {0 , 1 , 0 , -1}; // clockwise from north
int dy[4] = {-1 , 0 , 1 , 0};
int dx2[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1}; // clockwise from north
int dy2[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
const int N = 5000 + 50, M = 100 + 50, L = 25;
int64_t n,l,k;
template<int64_t MOD_ = mod1> struct modint_t {
  static constexpr int64_t MOD = MOD_;
  static_assert(MOD_ > 0);
  int64_t val;
  modint_t(int64_t _val = 0) : val(_val % MOD) {
    if(val < 0) val += MOD;
  }
  explicit operator int64_t() const {
    return val;
  }
  int64_t get_mod(){
    return MOD;
  }
  friend std::ostream& operator<<(std::ostream& out, const modint_t& p){
    out << int64_t(p);
    return out;
  }
  friend std::istream& operator>>(std::istream& in, modint_t& p){
    int64_t v;
    in >> v;
    p = modint_t(v);
    return in;
  }
  modint_t operator+ (modint_t other) const {
    return modint_t(val + other.val);
  }
  void operator+= (modint_t other){
    val += other.val;
    val %= MOD;
  }
  modint_t operator- () const {
    return modint_t(MOD - val);
  }
  modint_t operator- (modint_t other) const {
    return modint_t(val + MOD - other.val);
  }
  void operator-= (modint_t other) {
    val += MOD - other.val;
    val %= MOD;
  }
  modint_t operator* (modint_t other) const {
    return modint_t(val * other.val);
  }
  void operator*= (modint_t other) {
    val *= other.val;
    val %= MOD;
  }
  bool operator== (modint_t other) const {
    return val == other.val;
  }
  bool operator!= (modint_t other) const {
    return val != other.val;
  }
  modint_t& operator++() {
    val = (val + 1) % MOD;
    return *this;
  }    
  modint_t operator++(int) {
    modint_t temp = *this;
    ++(*this);
    return temp;
  }  
  modint_t& operator--() {
    val = (val - 1 + MOD) % MOD;
    return *this;  
  }  
  modint_t operator--(int) {
    modint_t temp = *this;
    --(*this);
    return temp;
  } 
};
template<int64_t MOD_ = mod1>
modint_t<MOD_> power(modint_t<MOD_> a, int64_t p) {
  assert(p >= 0);
  return p == 0 ? modint_t<MOD_>(1) : power<MOD_>(a * a, p / 2) * modint_t<MOD_>(p & 1 ? a : 1);
}
template<int64_t MOD_ = mod1>
modint_t<MOD_> inverse (modint_t<MOD_> a) {
  assert(int64_t(a) != 0);
  return power<MOD_>(a, MOD_ - 2);
}
template<int64_t MOD_ = mod1>
modint_t<MOD_> operator/(modint_t<MOD_> a, modint_t<MOD_> b) {
  return a * inverse(b);
}
template<int64_t MOD_ = mod1>
modint_t<MOD_> operator/(modint_t<MOD_> a, int64_t b) {
  return a / modint_t<MOD_>(b);
}
template<int64_t MOD_ = mod1>
modint_t<MOD_>& operator/=(modint_t<MOD_> &a, modint_t<MOD_> b) {
  return a = a / b;
}
template<int64_t MOD_ = mod1>
modint_t<MOD_> operator/=(modint_t<MOD_> &a, int64_t b) {
  return a = a / modint_t<MOD_>(b);
} 

using mint64_t = modint_t<>;
using mll = mint64_t;
mint64_t dp[N][M];
int32_t main(){
#ifdef AlRntn
freopen("inputf.in" , "r" , stdin); freopen("outputf.out" , "w" , stdout); freopen("errorf.out" , "w" , stderr);
#endif
  using namespace std;
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int32_t tc=1;
#define TestCases
#ifdef TestCases
  std::cin >> tc;
#endif
  while(tc--){
    cin>>n>>l>>k;
    assert(k == 0);
    dp[1][1] = 1;
    for(int64_t i=2;i<=l;i++){
      auto inv = inverse(mint64_t(i));
      std::vector<int64_t> cnt(n+1, 0);
      for(int64_t xx=1;xx<=i;xx++) cnt[((xx%n) ? (xx%n) : n)]++;
      for(int64_t pos=1;pos<=n;pos++){
        for(int64_t shift=1;shift<=n;shift++){
          dp[i][((pos + shift)%n ? (pos + shift)%n : n)] += inv * (dp[i-1][shift] * cnt[pos]);
        }
        dp[i][pos] += inv * mint64_t(cnt[pos]);
      }
    }
    for(int64_t i=1;i<=n;i++){
      cout << dp[l][i] << spc;
    }
    cout << endl;
    for(int64_t i=0;i<=l;i++){
      for(int64_t j=0;j<=n;j++) dp[i][j]=0;
    }
  }
  return 0;
}