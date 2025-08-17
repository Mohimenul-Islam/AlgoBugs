#include <bits/stdc++.h>

using namespace std;

long long ost = 1000000007;
vector<vector<long long>> gr;
vector<long long> d;
vector<long long> used;
bool isOk;
long long q;


void isClc(long long h, long long pr) {
    used[h] = 1;
    for (auto v : gr[h]) {
        if (v == pr) {
            continue;
        }
        if (used[v] == 1) {
            isOk = false;
            return;
        }
        if (used[v] == 2) {
            continue;
        }
        isClc(v, h);
    }
    used[h] = 2;
}


int dfs(long long h, long long pr) {
    int w = 0;
    bool isLeaf = true;
    for (auto v : gr[h]) {
        if (v == pr) {
            continue;
        }
        isLeaf = false;
        long long rs = dfs(v, h);
        if (!rs) {
            w++;
        }
        d[h] += rs;
    }
    if (pr != -1) {
        if (gr[pr].size() > 1) {
            w++;
        } else {
            d[h]++;
        }
    }
    if (w && !isLeaf) {
        q++;
    }
    if (w > 2) {
        isOk = false;
    }
    if (isLeaf) {
        return 1;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<long long> fct(2 * 100001, 1);
    for (int i = 1; i <= 2 * 100000; i++) {
        fct[i] = (fct[i - 1] * i) % ost;
    }
    long long t;
    cin >> t;
    for (long long test = 0; test < t; test++) {
        long long n, m;
        cin >> n >> m;
        gr.assign(n, {});
        d.assign(n, {});
        used.assign(n, 0);
        isOk = true;
        q = 0;
        for (long long i = 0; i < m; i++) {
            long long x, y;
            cin >> x >> y;
            x--;
            y--;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        isClc(0, -1);
        if (!isOk) {
            cout << 0 << '\n';
            continue;
        }
        dfs(0, -1);
        if (!isOk) {
            cout << 0 << '\n';
            continue;
        }
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= fct[d[i]];
            ans %= ost;
        }
        if (q < 2) {
            ans *= 2;
        } else {
            ans *= 4;
        }
        ans %= ost;
        cout << ans << '\n';
    }
}