#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> d(n + 1, 0);
    vector<vector<int>> v(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
    
        v[x].push_back(y);
        v[y].push_back(x);
        d[x]++; d[y]++;
    }
    if (m != n - 1) {
        printf("0\n");
        return;
    }
    vector<int> fact(n + 1, 0);
    int mod = 1000000007;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    int p = 1, q = 0;
    for (int i = 1; i <= n; i++) if (d[i] > 1) {
        int z = 0;
        q++;
        for (auto x : v[i]) if (d[x] == 1) z++;
        if ((int) v[i].size() - z >= 3) {
            printf("0\n");
            return;
        }
        p = (1LL * p * fact[z]) % mod;
    }
    if (q == 0) {
        printf("2\n");
    } else if (q == 1) {
        printf("%d\n", int(2LL * p % mod));
    } else {
        printf("%d\n", int(4LL * p % mod));
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
