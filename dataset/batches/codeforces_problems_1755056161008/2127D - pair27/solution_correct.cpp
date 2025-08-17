#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <unordered_map>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <stack>
#include <iomanip>
#include <functional>
#include <numeric>
#include <unordered_set>
#include <bitset>
 
#define all(x) x.begin(), x.end()
#define int long long
#define N (1000004)
 
using namespace std;
 
const int mod = 1000000007;
const int INF = 1e9;

vector<int> fact(N);
vector<int> inv_fact(N);
 
int bin_pow(int n, int step) {
    if (step == 0) return 1;
    if (step == 1) return n % mod;
 
    if (step % 2 == 0) return bin_pow(n * n % mod, step/2);
    else               return (n * bin_pow(n, step - 1)) % mod;
}
 
int inv(int n) {
    return bin_pow(n, mod - 2);
}
 
int mul(int f, int s) {
    return (f * s) % mod;
}
 
void fill() {
    fact[0] = 1;
    for (int i = 1;i < N;i++) {
        fact[i] = mul(fact[i - 1], i);
    }
 
    inv_fact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2;i >= 0;i--)
        inv_fact[i] = mul(inv_fact[i + 1], i + 1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<int> deg(n, 0);
    for (int i = 0;i < m;i++) {
        int f, s;
        cin >> f >> s;
        f--; s--;
        g[f].push_back(s);
        g[s].push_back(f);

        deg[f]++;
        deg[s]++;
    }
    if (m != n - 1) {
        cout << "0\n";
        return;
    }
    if (n == 2) {
        cout << "2\n";
        return;
    }
    int cnt_deg_gr_1 = 0;
    for (int i = 0;i < n;i++)
        cnt_deg_gr_1 += (deg[i] > 1 ? 1 : 0);

    if (cnt_deg_gr_1 == 1) {
        cout << mul(fact[n - 1], 2) << "\n";
        return;
    }
    
    int start = -1;
    int end = -1;
    vector<int> is_op(n, -1);
    for (int i = 0;i < n;i++) {
        if (deg[i] > 1) {
            is_op[i] = 1;

            int cur_cnt_oporn = 0;
            for (int to : g[i])
                cur_cnt_oporn += (deg[to] > 1 ? 1 : 0);
            if (cur_cnt_oporn == 1) {
                if (start != -1) {
                    cout << "0\n";
                    return;
                }
                start = end;
                end = i;
            }
        }
    }

    // cout << start + 1 << " " << end + 1 << "\n";
    // check for right tree
    int ans = 1;
    for (int i = 0;i < n;i++) {
        if (start == i || end == i) ans = mul(ans, fact[deg[i] - 1]);
        else if (is_op[i] == 1)     ans = mul(ans, fact[deg[i] - 2]);
    }
    ans = mul(ans, 2);
    ans = mul(ans, 2);
    cout << ans << "\n";
}

signed main() {
    fill();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1;i <= t;i++)
        solve();
 
    return 0;
}