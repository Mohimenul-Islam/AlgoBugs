#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod = 1e9 + 7;
constexpr int N = 2e5 + 10;
int n, s, x;
int num[N];
bool vis[N];
int dp[N];
int cal(int l, int r)
{
	unordered_map<int, int> mp;
	// mp[0]=bool(s);
	int left_x = l - 1;
	int ans = 0;
	for (int i = l; i <= r; i++)
	{
		dp[i] = dp[i - 1] + num[i];
		if (num[i] == x)
		{
			while (left_x < i)
			{
				mp[dp[left_x]]++;
				left_x++;
			}
		}

		if (mp.count(dp[i] - s))
		{
			ans += mp[dp[i] - s];
		}
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n >> s >> x;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			dp[i] = 0;
			vis[i] = false;
		}
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
			{
				continue;
			}
			if (num[i] == x)
			{
				int l = i, r = i;
				while (num[l] <= x && l)
				{
					vis[l] = true;
					l--;
				}
				while (num[r] <= x && r <= n)
				{
					vis[r] = true;
					r++;
				}
				ans += cal(l + 1, r - 1);
			}
		}
		cout << ans << '\n';
	}
}