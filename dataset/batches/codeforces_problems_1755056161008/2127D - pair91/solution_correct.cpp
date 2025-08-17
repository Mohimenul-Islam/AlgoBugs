#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fType int
#define foreach(x, a, b) for (fType x = a, _end_ = b; x <= _end_; x++)
#define foreach_sub(x, a, b) for (fType x = a, _end_ = b; x >= _end_; x--)

const ll MOD = 1000000007;
struct ModInt
{
    ll val;
    ModInt() : val(0) {}
    ModInt(ll x) : val(x % MOD) {}

    friend ModInt operator+(const ModInt &A, const ModInt &B)
    {
        return ModInt(A.val + B.val);
    }

    friend ModInt operator*(const ModInt &A, const ModInt &B)
    {
        return ModInt(A.val * B.val);
    }

    friend ModInt operator-(const ModInt &A, const ModInt &B)
    {
        if (!B.val) return A;
        return ModInt(A.val + MOD - B.val);
    }
};

ModInt qpow(ModInt x, ll p)
{
    ModInt res = 1;
    for (; p; p >>= 1, x = x * x)
        if (p & 1) res = res * x;

    return res;
}

const ll X = 200000;
ModInt jc[X + 2], ijc[X + 2];
ll Init = [](ll n) -> ll
{
    jc[0] = 1;
    foreach (i, 1, n)
        jc[i] = jc[i - 1] * ModInt(i);

    ijc[n] = qpow(jc[n], MOD - 2);
    foreach_sub (i, n - 1, 1)
    {
        ijc[i] = ijc[i + 1] * ModInt(i + 1);
    }
    ijc[0] = 1;

    return 0;
}(X);

//

const int N = 200020;
int n, m;

using vT = vector<vector<int>>;
vT gp;

bool vis[N];

//

bool dfs_cir(int u, int fa)
{
    vis[u] = 1;

    for (auto &v : gp[u])
    {
        if (v == fa) continue;

        // 有环
        if (vis[v]) return 1;
        if (dfs_cir(v, u)) return 1;
    }

    return 0;
}

bool checkCir()
{
    fill(vis + 1, vis + n + 1, 0);

    foreach (i, 1, n)
        if (!vis[i])
            if (dfs_cir(i, 0)) return 1;

    return 0;
}

//

int sz[N], cnt[N];
void initSz(int u, int fa)
{
    sz[u] = 1;
    cnt[u] = 0;

    for (auto &v : gp[u])
    {
        if (v == fa) continue;

        initSz(v, u);

        sz[u] += sz[v];
        cnt[u] += sz[v] == 1;
    }
}

bool flag = 1;
ModInt solve(int u, int fa)
{
    sz[u] = 1;

    int tmp = 0, tmp2 = 0;
    for (auto &v : gp[u])
    {
        if (v == fa) continue;
        vis[v] = 1;

        if (sz[v] > 1)
            ++tmp;
        else
            ++tmp2;
    }

    // 分支过多
    if (tmp > 1 + !fa)
    {
        flag = 0;
        return 0;
    }

    ModInt res = jc[tmp2];

    if (tmp)
    {
        for (auto &v : gp[u])
        {
            if (v == fa) continue;
            if (sz[v] > 1) res = res * solve(v, u);

            if (!flag) return 0;
        }
    }

    if (!fa && tmp) res = res * 2;

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int _;
    cin >> _;

    while (_--)
    {
        cin >> n >> m;

        gp = vT(n + 1);

        foreach (i, 1, m)
        {
            int u, v;
            cin >> u >> v;

            gp[u].emplace_back(v);
            gp[v].emplace_back(u);
        }

        if (checkCir())
        {
            puts("0");
            continue;
        }

        fill(vis + 1, vis + n + 1, 0);
        flag = 1;

        ll blockCnt = 0;
        ModInt ans = 1;
        foreach (i, 1, n)
        {
            if (!vis[i])
            {
                int u = i;
                if (gp[u].size() == 1) u = gp[u][0]; // root 修正, 确保 root 在主干上

                initSz(u, 0);
                vis[u] = 1;

                ++blockCnt;
                ans = ans * (solve(u, 0) * 2);

                if (!flag) break;
            }
        }

        ans = jc[blockCnt] * ans;

        if (flag)
            printf("%lld\n", ans.val);
        else
            puts("0");
    }

    return 0;
}