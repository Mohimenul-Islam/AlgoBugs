#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi")

using namespace std;
using ll = long long;
using ld = long double;
using i128 = __int128;

vector <vector <int>> gr;
vector <int> used, pred, c;
array <int, 2> ans;

void dfs(int v, int p, int d){
    c[v] = 1;
    pred[v] = p;
    ans = max(ans, {d, v});
    for (auto u : gr[v]){
        if (u != p & !used[u]){
            dfs(u, v, d + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    gr.assign(n, {});
    for (int i = 0; i < n - 1; ++i){
        int v, u;
        cin >> v >> u;
        --v, --u;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    vector <array <int, 3>> a;
    used.assign(n, 0);
    pred.assign(n, 0);
    int any;
    do {
        any = 0;
        c.assign(n, 0);
        for (int v = 0; v < n; ++v){
            if (!used[v] & !c[v]){
                any = 1;
                ans = {0, 0};
                dfs(v, -1, 1);
                int u = ans[1];
                ans = {0, 0};
                dfs(u, -1, 1);
                a.push_back({ans[0], ans[1], u});
                if (a.back()[1] < a.back()[2]){
                    swap(a.back()[1], a.back()[2]);
                }
                u = ans[1];
                while (pred[u] != -1){
                    used[u] = 1;
                    u = pred[u];
                }
                used[u] = 1;
            }
        }
    } while (any);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (auto [d, v, u] : a){
        cout << d << ' ' << v + 1 << ' ' << u + 1 << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
        cout << '\n';
    }
}
