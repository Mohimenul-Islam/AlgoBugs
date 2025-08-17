#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi")

using namespace std;
using ll = long long;
using ld = long double;
using i128 = __int128;

vector <vector <int>> gr;
vector <array <int, 2>> dp;
vector <int> used, pred, c;
int timer;

void dfs(int v, int p){
    c[v] = timer;
    dp[v] = {1, v};
    pred[v] = v;
    for (auto u : gr[v]){
        if (u != p & !used[u]){
            dfs(u, v);
            if (dp[u][0] + 1 > dp[v][0] | ((dp[u][0] + 1 == dp[v][0]) & (dp[u][1] > dp[v][1]))){
                dp[v] = {dp[u][0] + 1, dp[u][1]};
                pred[v] = u;
            }
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
    dp.assign(n, {});
    used.assign(n, 0);
    pred.assign(n, 0);
    c.assign(n, 0);
    timer = 0;
    dfs(0, -1);
    int w = dp[0][1];
    dfs(w, -1);
    set <array <int, 3>, greater <array <int, 3>>> b;
    b.insert({dp[w][0], dp[w][1], w});
    while (pred[w] != w){
        used[w] = 1;
        w = pred[w];
    }
    used[w] = 1;
    vector <vector <int>> a(n);
    for (int v = 0; v < n; ++v){
        a[0].push_back(v);
    }
    while (b.size()){
        auto [d, s, t] = *b.begin();
        if (s < t){
            swap(s, t);
        }
        cout << d << ' ' << s + 1 << ' ' << t + 1 << ' ';
        b.erase(b.begin());
        int cur = c[s];
        for (auto v : a[cur]){
            if (used[v]){
                continue;
            }
            if (c[v] == cur){
                timer++;
                dfs(v, -1);
                int w = dp[v][1];
                dfs(w, -1);
                b.insert({dp[w][0], dp[w][1], w});
                while (pred[w] != w){
                    used[w] = 1;
                    w = pred[w];
                }
                used[w] = 1;
            }
            a[c[v]].push_back(v);
        }
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
