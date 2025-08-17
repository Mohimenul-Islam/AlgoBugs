#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<long long> dp(n+1, 0);
    dp[n-1]=1;
    for (int i = n - 2; i >= 0; i--)
    {
        if(v[i]>v[i+1]){
            dp[i]=dp[i+1]+n-i;
        }
        else{
            dp[i]=dp[i+2]+n-i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans += dp[i];
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}