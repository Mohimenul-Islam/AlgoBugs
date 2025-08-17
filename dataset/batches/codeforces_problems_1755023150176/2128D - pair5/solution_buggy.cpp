// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse-lm")
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define eps 1e-7
using namespace std;

const double PI = acos(-1);
const int N = 5e5 + 10;

ll n, p[N], dp[N];

void solve()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &p[i]);
        dp[i] = 0;
    }

    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (p[i] > p[i + 1])
            dp[i] = (n - i) + dp[i + 1];
        else
            dp[i] = (n - i) + dp[i + 2];
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += dp[i];
    cout << res << "\n";
}
int main()
{
    int _ = 1;
    scanf("%d", &_);
    while (_--)
    {
        solve();
    }

    return 0;
}