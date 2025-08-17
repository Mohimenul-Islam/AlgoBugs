#include <bits/stdc++.h>
#include <limits>

using namespace std;
using i64 = int64_t;

const size_t N = 2e5;
vector<size_t> LOG;

template <typename T> struct SparseTable {
  size_t n;
  size_t log;
  vector<vector<T>> arr;

  void build(const vector<T> &a) {
    n = a.size();
    log = LOG[n];

    arr.resize(log + 1);
    arr[0] = a;

    for (int j = 1; j <= log; j++) {
      arr[j].resize(n);
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        arr[j][i] = max(arr[j - 1][i], arr[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T operator()(int a, int b) const {
    if (a < 0) {
      return numeric_limits<T>::max();
    }

    if (b >= n) {
      return numeric_limits<T>::min();
    }

    const int h = LOG[(b + 1 - a)];
    return max(arr[h][a], arr[h][b - (1 << h) + 1]);
  }
};

void solve() {
  i64 n, s, x;
  cin >> n >> s >> x;

  vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  SparseTable<i64> st;
  st.build(a);

  map<i64, vector<int>> pref = {{0, {0}}};

  i64 sum = 0;
  i64 ans = 0;
  for (size_t i = 0; i < n; ++i) {
    sum += a[i];

    const auto &vec = pref[sum - s];

    i64 l = -1, r = vec.size();
    while (r - l > 1) {
      auto m = (l + r) / 2;

      if (st(vec[m], i) >= x) {
        l = m;
      } else {
        r = m;
      }
    }

    if (l != -1) {
      i64 L = -1, R = r;
      while (R - L > 1) {
        auto m = (L + R) / 2;

        if (st(vec[m], i) > x) {
          L = m;
        } else {
          R = m;
        }
      }

      if (L < l && l < vec.size() && st(vec[l], i) == x) {
        ans += (l - L);
      }
    }

    pref[sum].push_back(i + 1);
  }

  cout << ans << '\n';
}

int main() {
  LOG.resize(N + 1, 0);
  for (size_t i = 2; i <= N; i++) {
    LOG[i] = LOG[i / 2] + 1;
  }

  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t-- > 0)
    solve();
}
