#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using ld = long double;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;
constexpr int dir4[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
constexpr int dir8[8][2] = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                            {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
constexpr int maxinf = 1E9;
constexpr i64 maxinff = 1E18;
constexpr i64 mininf = -1E9;
constexpr i64 mininff = -1E18;
#if defined(ENABLE_FASTIO)
struct FastIO {
  static const int S = 1 << 18;
  char ibuf[S], *p1, *p2;
  char obuf[S], *p3 = obuf;
  FastIO() : p1(ibuf), p2(ibuf) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  }
  inline char getch() {
    if (p1 == p2)
      p1 = ibuf, p2 = ibuf + fread(ibuf, 1, S, stdin);
    return p1 == p2 ? EOF : *p1++;
  }
  template <typename T>
      typename std::enable_if<std::is_integral<T>::value,
                              FastIO &>::typeoperator >>
      (T & x) {
    x = 0;
    char c = getch();
    bool sign = 0;
    while (!isdigit(c))
      sign |= (c == '-'), c = getch();
    while (isdigit(c))
      x = x * 10 + (c ^ '0'), c = getch();
    if (sign)
      x = -x;
    return *this;
  }
  template <typename T>
      typename std::enable_if<std::is_floating_point<T>::value,
                              FastIO &>::typeoperator >>
      (T & x) {
    x = 0.0;
    double frac = 1.0;
    char c = getch();
    bool sign = 0, after_dot = 0;
    while (!isdigit(c) && c != '.')
      sign |= (c == '-'), c = getch();
    while (isdigit(c) || c == '.') {
      if (c == '.')
        after_dot = 1;
      else if (!after_dot)
        x = x * 10 + (c - '0');
      else {
        frac *= 0.1;
        x += (c - '0') * frac;
      }
      c = getch();
    }
    if (sign)
      x = -x;
    return *this;
  }
  FastIO &operator>>(char *s) {
    int cnt = 0;
    char c = getch();
    while (isspace(c))
      c = getch();
    while (!isspace(c) && c != EOF)
      s[cnt++] = c, c = getch();
    s[cnt] = '\0';
    return *this;
  }
  template <typename T>
  typename std::enable_if<!std::is_arithmetic<T>::value, FastIO &>::type
  operator>>(T &x) {
    x.read(*this);
    return *this;
  }
  inline void putch(char c) {
    if (p3 - obuf >= S)
      flush();
    *p3++ = c;
  }
  template <typename T>
      typename std::enable_if<std::is_integral<T>::value,
                              FastIO &>::typeoperator
      << (T x) {
    static char stk[40];
    int top = 0;
    if (x < 0)
      putch('-'), x = -x;
    do
      stk[top++] = x % 10 + '0', x /= 10;
    while (x);
    while (top)
      putch(stk[--top]);
    return *this;
  }
  template <typename T>
      typename std::enable_if<std::is_floating_point<T>::value,
                              FastIO &>::typeoperator
      << (T x) {
    const int precision = 6;
    if (x < 0)
      putch('-'), x = -x;
    long long integer = static_cast<long long>(x);
    *this << integer << '.';
    x -= integer;
    for (int i = 0; i < precision; ++i) {
      x *= 10;
      int digit = static_cast<int>(x);
      putch(digit + '0');
      x -= digit;
    }
    return *this;
  }
  FastIO &operator<<(const char *s) {
    while (*s)
      putch(*s++);
    return *this;
  }
  template <typename T>
      typename std::enable_if<!std::is_arithmetic<T>::value,
                              FastIO &>::typeoperator
      << (const T &x) {
    x.write(*this);
    return *this;
  }
  friend FastIO &operator>>(FastIO &fio, std::string &s) {
    s.clear();
    char c = fio.getch();
    while (isspace(c))
      c = fio.getch();
    while (!isspace(c) && c != EOF) {
      s.push_back(c);
      c = fio.getch();
    }
    return fio;
  }
  friend FastIO &operator<<(FastIO &fio, const std::string &s) {
    for (char c : s)
      fio.putch(c);
    return fio;
  }
  void flush() { fwrite(obuf, 1, p3 - obuf, stdout), p3 = obuf; }
  ~FastIO() { flush(); }
} fio;
#define cin fio
#define cout fio
#else
struct FastIO {
  FastIO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed;
  }
} fio;
#endif
#define LOCAL
#if defined(LOCAL)
#define SHOW(...)                                                              \
  SHOW_IMPL(__VA_ARGS__, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)
#define SHOW_IMPL(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define SHOW1(x) std::cerr << #x << " = " << (x) << std::endl
#define SHOW2(x, y)                                                            \
  std::cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << std::endl
#define SHOW3(x, y, z)                                                         \
  std::cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z  \
            << " = " << (z) << std::endl
#define SHOW4(x, y, z, w)                                                      \
  std::cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z  \
            << " = " << (z) << ", " << #w << " = " << (w) << std::endl
#define SHOW5(x, y, z, w, v)                                                   \
  std::cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z  \
            << " = " << (z) << ", " << #w << " = " << (w) << ", " << #v        \
            << " = " << (v) << std::endl
#else
#define SHOW(...)
#endif
#define DEBUG 1
#ifdef DEBUG
#define dbg(...)                                                               \
  std::cerr << "DEBUG [Line " << __LINE__ << "] " << #__VA_ARGS__ << " = ",    \
      debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif
void debug_out() { std::cerr << std::endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  std::cerr << H;
  if (sizeof...(T))
    std::cerr << ", ";
  debug_out(T...);
}
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define stoi stoll
#define popf pop_front
#define popb pop_back
#define pbf push_front
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(v) v.begin(), v.end()
#define onebits(x) __builtin_popcountll(x)       // 二进制1
#define zerobits(x) __builtin_ctzll(x)           // 末尾0
#define toone_bit(x, i) ((x) |= (1LL << (i)))    // i位置1
#define clear_bit(x, i) ((x) &= ~(1LL << (i)))   // 清为0
#define rev_bit(x, i) ((x) ^= (1LL << (i)))      // 取反
#define check_bit(x, i) (!!((x) & (1LL << (i)))) // 是否为1
#define ps(y) cout << fixed << setprecision(y)
#define rep2(a) for (decay_t<decltype(a)> _ = 0; _ < (a); ++_)
#define rep3(i, a) for (decay_t<decltype(a)> i = 0; i < (a); ++i)
#define rep4(i, a, b) for (decay_t<decltype(b)> i = a; i < (b); ++i)
#define rep5(i, a, b, c) for (decay_t<decltype(b)> i = a; i < (b); i += (c))
#define rep6(a) for (decay_t<decltype(a)> _ = 1; _ <= (a); ++_)
#define rep7(i, a) for (decay_t<decltype(a)> i = 1; i <= (a); ++i)
#define rep8(i, a, b) for (decay_t<decltype(b)> i = a; i <= (b); ++i)
#define rep9(i, a, b, c) for (decay_t<decltype(b)> i = a; i <= (b); i += (c))
#define per2(a) for (decay_t<decltype(a)> _ = (a) - 1; _ >= (0); --_)
#define per3(i, a) for (decay_t<decltype(a)> i = (a) - 1; i >= (0); --i)
#define per4(i, a, b) for (decay_t<decltype(b)> i = (b) - 1; i >= (a); --i)
#define per5(i, a, b, c)                                                       \
  for (decay_t<decltype(b)> i = (b) - 1; i >= (a); i -= (c))
#define per6(a) for (decay_t<decltype(a)> _ = (a); _ >= 1; --_)
#define per7(i, a) for (decay_t<decltype(a)> i = (a); i >= 1; --i)
#define per8(i, a, b) for (decay_t<decltype(b)> i = (b); i >= (a); --i)
#define per9(i, a, b, c) for (decay_t<decltype(b)> i = (b); i >= (a); i -= (c))
#define rev1(v) reverse(all(v))
#define rev2(first, last) std::reverse((first), (last))
#define overload4(a, b, c, d, e, ...) e
#define overloadr(a, b, c, ...) e
#define rev(...) overloadr(__VA_ARGS__, rev1, rev2)(__VA_ARGS__)
#define rep0(...) overload4(__VA_ARGS__, rep5, rep4, rep3, rep2)(__VA_ARGS__)
#define rep1(...) overload4(__VA_ARGS__, rep9, rep8, rep7, rep6)(__VA_ARGS__)
#define per0(...) overload4(__VA_ARGS__, per5, per4, per3, per2)(__VA_ARGS__)
#define per1(...) overload4(__VA_ARGS__, per9, per8, per7, per6)(__VA_ARGS__)
#define overload_scanf(_1, _2, _3, NAME, ...) NAME
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define lbg(c, x) distance((c).begin(), lower_bound(all(c), (x), greater{}))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define ubg(c, x) distance((c).begin(), upper_bound(all(c), (x), greater{}))
#define uniq(x) sort(all(x)), x.erase(unique(all(x)), x.end())
template <typename T> int sz(const T &x) { return static_cast<int>(x.size()); }
template <typename T> void sc(T &value) {
  if constexpr (is_same_v<T, int>) {
    scanf("%d", &value);
  } else if constexpr (is_same_v<T, char>) {
    scanf(" %c", &value);
  } else if constexpr (is_same_v<T, long long>) {
    scanf("%lld", &value);
  }
}
template <typename T, typename U> void sc2(T &value1, U &value2) {
  sc(value1);
  sc(value2);
}
template <typename T, typename U, typename V>
void sc3(T &value1, U &value2, V &value3) {
  sc(value1);
  sc(value2);
  sc(value3);
}
#define sc(...) overload_scanf(__VA_ARGS__, sc3, sc2, sc)(__VA_ARGS__)
#define overload_printf(_1, _2, _3, NAME, ...) NAME
template <typename T> void pr(T value) {
  if constexpr (is_same_v<T, int>) {
    printf("%d ", value);
  } else if constexpr (is_same_v<T, char>) {
    printf("%c ", value);
  } else if constexpr (is_same_v<T, long long>) {
    printf("%lld ", value);
  }
}
template <typename T, typename U> void pr2(T value1, U value2) {
  pr(value1);
  pr(value2);
}
template <typename T, typename U, typename V>
void pr3(T value1, U value2, V value3) {
  pr(value1);
  pr(value2);
  pr(value3);
}
#define pr(...) overload_printf(__VA_ARGS__, pr3, pr2, pr)(__VA_ARGS__)
template <class T> auto minarray(const T &a) { return *min_element(all(a)); }
template <class T> auto maxarray(const T &a) { return *max_element(all(a)); }
template <class T1> istream &operator>>(istream &cin, vector<T1> &a) {
  for (auto &x : a)
    cin >> x;
  return cin;
}
template <class T1> ostream &operator<<(ostream &cout, vector<T1> a) {
  int n = a.size();
  if (!n)
    return cout;
  cout << a[0];
  for (int i = 1; i < n; i++)
    cout << ' ' << a[i];
  return cout;
}
istream &operator>>(istream &cin, i128 &x) {
  bool flg = 0;
  x = 0;
  static string s;
  cin >> s;
  if (s[0] == '-')
    flg = 1, s = s.substr(1);
  for (char c : s)
    x = x * 10 + (c - '0');
  if (flg)
    x = -x;
  return cin;
}
ostream &operator<<(ostream &cout, i128 x) {
  static char s[60];
  if (x < 0)
    cout << '-', x = -x;
  int tp = 1;
  s[0] = '0' + (x % 10);
  while (x /= 10)
    s[tp++] = '0' + (x % 10);
  while (tp--)
    cout << s[tp];
  return cout;
}
template <typename T1, typename T2> inline T1 min(T1 a, T2 b) {
  b = (T1)b;
  return a > b ? b : a;
}
template <typename T1, typename T2> inline T1 max(T1 a, T2 b) {
  b = (T1)b;
  return a > b ? a : b;
}
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <typename T, typename U> T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}
template <typename T, typename U> T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}
template <class T>
std::ostream &operator<<(std::ostream &cout,
                         const std::vector<std::vector<T>> &a) {
  for (const auto &row : a) {
    cout << row << '\n';
  }
  return cout;
}
template <class T> void rsort(vector<T> &v) { sort(v.rbegin(), v.rend()); }
template <class T> void sort(vector<T> &v) { sort(v.begin(), v.end()); }
template <class Iterator> void rsort(Iterator first, Iterator last) {
  sort(first, last, greater<typename iterator_traits<Iterator>::value_type>());
}
template <typename T> using pii = pair<T, T>;
template <typename T, typename T1> using ppi = pair<T, T1>;
template <typename T> using vpii = vector<pair<T, T>>;
template <typename T, typename T1> using vppi = vector<pair<T, T1>>;
template <typename T> using vi = vector<T>;
template <typename T> using vvi = vector<vector<T>>;
template <typename T, typename U> using umap = unordered_map<T, U>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using vti = vector<tuple<T, T, T>>;
template <typename T> using si = set<T>;
template <typename T, typename U> using mpi = map<T, U>;
template <typename T> using qi = queue<T>;
template <typename T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using pqmax = priority_queue<T, vector<T>, less<T>>;
template <typename T, size_t N> using arr = array<T, N>;

template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <typename T> T ksm(T a, T b) {
  T res = 1;
  while (b) {
    if (b & 1)
      res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
template <typename T> T ksm(T a, T b, T mod) {
  T res = 1;
  while (b) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
template <typename T> T inv(T a, T mod) { return pow_mod(a, mod - 2, mod); }
template <typename T> bool is_pow2(T x) { return x && !(x & (x - 1)); }
template <typename T> T next_pow2(T x) {
  return x ? T(1) << (sizeof(T) * 8 - clz(x)) : 1;
}
template <typename T> vector<T> presum(const vector<T> &v) {
  vector<T> res(v.size() + 1);
  for (int i = 0; i < v.size(); ++i)
    res[i + 1] = res[i] + v[i];
  return res;
}
template <typename T> vector<T> sufsum(const vector<T> &v) {
  vector<T> res(v.size() + 1);
  for (int i = (int)v.size() - 1; i >= 0; --i)
    res[i] = res[i + 1] + v[i];
  return res;
}
template <template <typename...> class Container = vector>
Container<string> split(const string &s, char delim = ' ') {
  Container<string> tokens;
  string token;
  istringstream iss(s);
  while (getline(iss, token, delim)) {
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }
  return tokens;
}
template <typename T> T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T> T ceil(T x, T y) { return floor(x + y - 1, y); }
template <typename T, typename U> T SUM(const vector<U> &A) {
  T sm = 0;
  for (auto &&a : A)
    sm += a;
  return sm;
}
template <typename T> vector<int> idxsort(const vector<T> &A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}
template <class T, size_t N>
std::istream &operator>>(std::istream &cin, std::array<T, N> &a) {
  for (auto &x : a)
    cin >> x;
  return cin;
}
template <class T, size_t N>
std::ostream &operator<<(std::ostream &cout, const std::array<T, N> &a) {
  for (size_t i = 0; i < N; ++i) {
    if (i > 0)
      cout << ' ';
    cout << a[i];
  }
  return cout;
}
template <class T, size_t N>
std::istream &operator>>(std::istream &cin, std::vector<std::array<T, N>> &vp) {
  for (auto &arr : vp) {
    cin >> arr;
  }
  return cin;
}
template <class T, size_t N>
std::ostream &operator<<(std::ostream &cout,
                         const std::vector<std::array<T, N>> &vp) {
  for (size_t i = 0; i < vp.size(); ++i) {
    if (i > 0)
      cout << '\n';
    cout << vp[i];
  }
  return cout;
}
template <typename T1, typename T2, typename T3> struct Node {
  T1 x;
  T2 y;
  T3 z;
  Node(T1 x = T1(), T2 y = T2(), T3 z = T3()) : x(x), y(y), z(z) {}
};
template <typename T1, typename T2, typename T3>
std::istream &operator>>(std::istream &cin, Node<T1, T2, T3> &a) {
  return cin >> a.x >> a.y >> a.z;
}
template <typename T1, typename T2, typename T3>
std::ostream &operator<<(std::ostream &cout, const Node<T1, T2, T3> &a) {
  return cout << a.x << ' ' << a.y << ' ' << a.z;
}
template <typename T1, typename T2, typename T3>
std::ostream &operator<<(std::ostream &cout,
                         const std::vector<Node<T1, T2, T3>> &a) {
  for (const auto &x : a) {
    cout << x << '\n';
  }
  return cout;
}
template <class T1, class T2>
istream &operator>>(istream &cin, pair<T1, T2> &a) {
  return cin >> a.first >> a.second;
}
template <class T1, class T2>
ostream &operator<<(ostream &cout, const pair<T1, T2> &a) {
  return cout << a.first << ' ' << a.second;
}
template <class T1, class T2>
ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) {
  for (auto &x : a)
    cout << x << '\n';
  return cout;
}
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
int popcnt(T x) {
  if constexpr (std::is_signed_v<T>) {
    return __builtin_popcountll(static_cast<unsigned long long>(x));
  } else {
    return __builtin_popcount(x);
  }
}
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
int popcnt_mod_2(T x) {
  if constexpr (std::is_signed_v<T>) {
    return __builtin_parityll(static_cast<unsigned long long>(x));
  } else {
    return __builtin_parity(x);
  }
}
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
int topbit(T x) {
  if (x == 0) {
    return -1;
  }
  if constexpr (std::is_signed_v<T>) {
    return 63 - __builtin_clzll(static_cast<unsigned long long>(x));
  } else {
    return (sizeof(T) * 8 - 1) - __builtin_clz(x);
  }
}
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
int lowbit(T x) {
  if (x == 0) {
    return -1;
  }
  if constexpr (std::is_signed_v<T>) {
    return __builtin_ctzll(static_cast<unsigned long long>(x));
  } else {
    return __builtin_ctz(x);
  }
}
template <typename T> vector<T> &operator+=(vector<T> &a, const vector<T> &b) {
  assert(a.size() == b.size());
  for (size_t i = 0; i < a.size(); ++i)
    a[i] += b[i];
  return a;
}
template <typename T> vector<T> operator+(vector<T> a, const vector<T> &b) {
  return a += b;
}
template <typename T> vector<T> &operator-=(vector<T> &a, const vector<T> &b) {
  assert(a.size() == b.size());
  for (size_t i = 0; i < a.size(); ++i)
    a[i] -= b[i];
  return a;
}
template <typename T> vector<T> operator-(vector<T> a, const vector<T> &b) {
  return a -= b;
}
template <typename T>
std::string vi_to_s(const vi<T> &vec, const std::string &delimiter) {
  if (vec.empty())
    return "";
  std::string result = std::to_string(vec[0]);
  for (size_t i = 1; i < vec.size(); ++i) {
    result += delimiter + std::to_string(vec[i]);
  }
  return result;
}
template <typename T> std::unordered_map<T, int> every_count(const vi<T> &vec) {
  std::unordered_map<T, int> cnt;
  for (const auto &element : vec) {
    ++cnt[element];
  }
  return cnt;
}
template <typename T> T max_count(const vi<T> &vec) {
  auto cnt = count_elements(vec);
  T res;
  int cntt = 0;
  for (const auto &pair : cnt) {
    if (pair.second > cntt) {
      cntt = pair.second;
      res = pair.first;
    }
  }
  return res;
}
vvi<int> readGraph1(int n, int m, bool ok = true) {
  vvi<int> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    if (ok)
      u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  return g;
}
vvi<int> readGraph0(int n, int m, bool ok = true) {
  vvi<int> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    if (ok)
      u--, v--;
    g[u].pb(v);
  }
  return g;
}
vvi<pii<int>> readvalGraph1(int n, int m, bool ok = true) {
  vvi<pii<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (ok)
      u--, v--;
    g[u].eb(v, w);
    g[v].eb(u, w);
  }
  return g;
}
vvi<pii<int>> readvalGraph0(int n, int m, bool ok = true) {
  vvi<pii<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (ok)
      u--, v--;
    g[u].eb(v, w);
  }
  return g;
}
template <class F> int find_max_true(int lw, int up, F f) {
  while (up - lw > 1) {
    int mid = (lw + up) / 2;
    if (f(mid))
      lw = mid;
    else
      up = mid;
  }
  return lw;
}
template <class F> int find_min_true(int lw, int up, F f) {
  while (up - lw > 1) {
    int mid = (lw + up) / 2;
    if (f(mid))
      up = mid;
    else
      lw = mid;
  }
  return up;
}
template <class t, class u> vi<t> &operator*=(vi<t> &a, u x) {
  for (auto &v : a)
    v *= x;
  return a;
}
template <class t, class u> vi<t> operator*(vi<t> a, u x) { return a *= x; }
template <class t, class u> vi<t> &operator/=(vi<t> &a, u x) {
  for (auto &v : a)
    v /= x;
  return a;
}
template <class t, class u> vi<t> operator/(vi<t> a, u x) { return a /= x; }
template <class t, class u> vi<t> &operator-=(vi<t> &a, u x) {
  for (auto &v : a)
    v -= x;
  return a;
}
template <class t, class u> vi<t> operator-(vi<t> a, u x) { return a -= x; }
template <class t, class u> vi<t> &operator+=(vi<t> &a, u x) {
  for (auto &v : a)
    v += x;
  return a;
}
template <class t, class u> vi<t> operator+(vi<t> a, u x) { return a += x; }
i128 toi128(const std::string &s) {
  i128 n = 0;
  for (auto c : s) {
    n = n * 10 + (c - '0');
  }
  return n;
}
i128 sqrti128(i128 n) {
  i128 lo = 0, hi = 1E16;
  while (lo < hi) {
    i128 x = (lo + hi + 1) / 2;
    if (x * x <= n) {
      lo = x;
    } else {
      hi = x - 1;
    }
  }
  return lo;
}
i128 gcd(i128 a, i128 b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}
bool o(int x) {
  bool t = (x % 2 == 0 ? 1 : 0);
  return t;
}
void YES(bool t = 1) { cout << (t ? "YES" : "NO") << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << (t ? "Yes" : "No") << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << (t ? "yes" : "no") << endl; } // split
void no(bool t = 1) { yes(!t); }
string to_lower(string s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}
string to_upper(string s) {
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}
vi<int> s_to_vi(const string &S, char first_char) {
  vi<int> A(S.size());
  for (int i = 0; i < sz(S); i++) {
    A[i] = (S[i] != '?' ? S[i] - first_char : -1);
  }
  return A;
}
//===================================================================================//

void solve() {
  int n, s, x;
  cin >> n >> s >> x;
  vi<int> a(n + 1), pre(n + 2);
  rep1(i, n) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  map<int, int> cnt;
  int l = 0;
  i64 ans=0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > x) {
      cnt.clear();
      l = i;
    } else {
      if (a[i] == x) {
        while (l < i) {
          cnt[pre[l++]]++;
        }
      }
      ans+=cnt[pre[i]-s];
    }
  }
  cout<<ans<<"\n";
}
//===================================================================================//
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}