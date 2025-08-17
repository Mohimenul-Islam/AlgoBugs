#include "bits/stdc++.h"

#ifndef rmaltsev
#define dbg(...)
#endif

#pragma GCC optimize("O3,unroll-loops")

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int sum(int a, int b) {
    return a + b - (a + b >= mod ? mod : 0);
}

int ml(int a, int b) {
    return 1LL * a * b % mod;
}

vector<vector<int>> gr;
vector<int> f;
int ans;

void precalc() {
    int n = 2e5 + 2;
    f.resize(n);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < n; ++i) {
        f[i] = ml(f[i - 1], i);
    }
}

void dfs(int u, int p = -1) {
    int cnt = gr[u].size(), fl = 0;
    for (auto to : gr[u]) {
        if (to == p) {
            --cnt;
            continue;
        }
        if (gr[to].size() != 1) {
            --cnt;
            dfs(to, u);
            fl = 1;
            break;
        }
    }
    int add = f[cnt];
    if (fl) add = ml(add, 2);
    if (gr[u].size() == 2 && p >= 0) add = 0;
    ans = sum(ans, add);
    dbg(u + 1, add);
}

void solve() {
    int n, m;
    cin >> n >> m;
    gr.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    if (m >= n) {
        cout << 0;
        return;
    }
    for (int u = 0; u < n; ++u) {
        int cnt = 0;
        for (auto to : gr[u]) {
            if (gr[to].size() > 1) {
                if (++cnt > 2) {
                    cout << 0;
                    return;
                }
            }
        }
    }
    if (n == 2) {
        cout << 2;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (gr[i].size() == 1) {
            ++cnt;
        }
    }
    cnt = n - cnt;
    if (cnt == 1) {
        cout << ml(2, f[n - 1]);
        return;
    }
    if (cnt == 2) {
        int x = -1, y = -1;
        for (int i = 0; i < n; ++i) {
            if (gr[i].size() > 1) {
                if (x < 0) {
                    x = gr[i].size();
                } else {
                    y = gr[i].size();
                }
            }
        }
        cout << ml(4, ml(f[x - 1], f[y - 1]));
        return;
    }
    int u = 0;
    for (; u < n; ++u) {
        if (gr[u].size() > 1) break;
    }
    u = min(u, n - 1);
    ans = 0;
    dfs(u);
    cout << ml(ans, 2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
        cout << '\n';
    }
}
