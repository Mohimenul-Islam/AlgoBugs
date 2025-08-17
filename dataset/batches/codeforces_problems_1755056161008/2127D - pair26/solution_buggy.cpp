#if !defined(__clang__) && defined(__GNUC__)
    #include <bits/stdc++.h>
using namespace std;
#endif

#ifndef LOCAL
class debug {
public:
    debug(bool = false) {
    }
    template <class c>
    debug &operator<<(c &) {
        return *this;
    }
    debug &operator<<(ostream &(*f)(ostream &)) {
        return *this;
    }
};
    #define imie(...) ""
    #define tabs(a)   ""
#else
    #include "Helpers.h"
#endif

void precalculate() {
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edgs(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edgs[u].push_back(v);
        edgs[v].push_back(u);
    }
    if (m > n - 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 2) {
        cout << 2 << endl;
        return;
    }
    const int modulo = 1000000000 + 7;
    int two          = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (auto v : edgs[i]) {
            if (edgs[v].size() > 2) {
                cnt++;
            }
        }
        if (cnt > 2) {
            cout << 0 << endl;
            return;
        }
        if (edgs[i].size() > 1)
            two = min(two + 1, 2);
    }
    debug() << imie(two);
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 0; i < n; ++i)
        fact[i + 1] = 1LL * fact[i] * (i + 1) % modulo;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (edgs[i].size() > 1) {
            function<void(int, int)> dfs = [&](int u, int p) {
                int cntZero = 0;
                for (auto v : edgs[u]) {
                    cntZero += edgs[v].size() == 1;
                    if (v == p)
                        continue;
                    if (edgs[v].size() > 1) {
                        dfs(v, u);
                    }
                }
                ans = 1LL * ans * fact[cntZero] % modulo;
            };
            dfs(i, -1);
            break;
        }
    }
    cout << ans * 2LL * two % modulo << endl;
}

int main(int argc, const char *argv[]) {
    // ios_base::sync_with_stdio(false);
#ifdef LOCAL
    // ifstream in("input_1.txt");
    freopen("input_1.txt", "r", stdin);
    // std::cin.tie(0);
    // std::cin.rdbuf(in.rdbuf());

    clock_t start = clock();
#endif
    precalculate();

    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        debug() << "Test Case #" << t << "       ---------------------------------------";
        solve();
    }

#ifdef LOCAL
    clock_t end         = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Execution time: " << elapsed_time << " seconds" << std::endl;
#endif

    return 0;
}
