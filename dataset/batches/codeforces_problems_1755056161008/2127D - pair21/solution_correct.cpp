/* -*- coding: utf-8 -*-
 *
 * 2127D.cc: D. Root was Built by Love, Broken by Destiny
 */

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

/* constant */

const int MAX_N = 200000;
const int MOD = 1000000007;

/* typedef */

using vi = vector<int>;

template<const int MOD>
struct MI {
  int v;
  MI(): v() {}
  MI(int _v): v(_v % MOD) { if (v < 0) v += MOD; }
  MI(long long _v): v(_v % MOD) { if (v < 0) v += MOD; }

  explicit operator int() const { return v; }
  
  MI operator+(const MI m) const { return MI(v + m.v); }
  MI operator-(const MI m) const { return MI(v + MOD - m.v); }
  MI operator-() const { return MI(MOD - v); }
  MI operator*(const MI m) const { return MI((long long)v * m.v); }

  MI &operator+=(const MI m) { return (*this = *this + m); }
  MI &operator-=(const MI m) { return (*this = *this - m); }
  MI &operator*=(const MI m) { return (*this = *this * m); }

  bool operator==(const MI m) const { return v == m.v; }
  bool operator!=(const MI m) const { return v != m.v; }

  MI pow(int n) const {  // a^n % MOD
    MI pm = 1, a = *this;
    while (n > 0) {
      if (n & 1) pm *= a;
      a *= a;
      n >>= 1;
    }
    return pm;
  }

  MI inv() const { return pow(MOD - 2); }
  MI operator/(const MI m) const { return *this * m.inv(); }
  MI &operator/=(const MI m) { return (*this = *this / m); }
};

using mi = MI<MOD>;

/* global variables */

mi fs[MAX_N + 1];
vi nbrs[MAX_N];
int ps[MAX_N], ds[MAX_N], cis[MAX_N];
int xds[MAX_N], cs0[MAX_N], cs1[MAX_N];

/* subroutines */

/* main */

int main() {
  fs[0] = 1;
  for (int i = 1; i <= MAX_N; i++) fs[i] = fs[i - 1] * i;
  
  int tn;
  scanf("%d", &tn);

  while (tn--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) nbrs[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }

    if (m != n - 1) { puts("0"); continue; }
    if (n == 2) { puts("2"); continue; }

    int rt = -1;
    for (int u = 0; u < n; u++)
      if (nbrs[u].size() >= 2) { rt = u; break; }

    fill(cis, cis + n, 0);
    fill(xds, xds + n, 0);
    fill(cs0, cs0 + n, 0);
    fill(cs1, cs1 + n, 0);
    ps[rt] = -1, ds[rt] = 0;
    mi w = 1;
    
    for (int u = rt; u >= 0;) {
      auto &nbru = nbrs[u];
      int up = ps[u];

      if (cis[u] < nbru.size()) {
	int v = nbru[cis[u]++];
	if (v != up) {
	  ps[v] = u, ds[v] = ds[u] + 1;
	  u = v;
	}
      }
      else {
	if (u == rt) {
	  if (cs1[u] > 2) { w = 0; break; }
	  w *= fs[cs0[u]] * (cs1[u] > 0 ? 2 : 1);
	}
	else {
	  if (cs1[u] > 1) { w = 0; break; }
	  w *= fs[cs0[u]];
	}
	
	xds[u] = max(xds[u], ds[u]);
	if (up >= 0) {
	  xds[up] = max(xds[up], xds[u]);
	  if (xds[u] > ds[up] + 1) cs1[up]++;
	  else cs0[up]++;
	}
	
	u = up;
      }
    }

    printf("%d\n", (int)(w * 2));
  }

  return 0;
}
