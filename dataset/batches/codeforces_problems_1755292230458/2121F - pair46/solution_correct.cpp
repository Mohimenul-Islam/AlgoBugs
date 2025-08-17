#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, s, x;
vector<int>a;
map<int, vector<int>>mp;
vector<int>sum;
vector<int>cnt;
int aa[N];
int res;
int check(int pos, int x,int t)
{
	return mp[t][x] >= pos && cnt[mp[t][x]] - cnt[pos - 1] > 0;
}
void work()
{
	for (int i = 1; i < a.size(); i++)
	{
		int t = sum.back();
		sum.push_back(t + a[i]);
		mp[t + a[i]].push_back(i);
		t = cnt.back();
		cnt.push_back(t + (a[i] == x));
	}
	for (int i = 1; i < a.size(); i++)
	{
		int t = sum[i - 1] + s;
		if (mp.count(t) == 0) continue;
		//for (auto c : mp[t])
		//{
		//	if (c >= i && cnt[c] - cnt[i - 1] > 0) res++;
		//}
		int l = 0, r = mp[t].size();
		while (l < r)
		{
			int mid = l + r >> 1;
			if (check(i, mid,t)) r = mid;
			else l = mid + 1;
		}
		res += mp[t].size() - l;
	}
}
void solve()
{
	res = 0;
	cin >> n >> s >> x;
	a.clear();
	mp.clear();
	sum.clear();
	cnt.clear();
	a.push_back(0);
	sum.push_back(0);
	cnt.push_back(0);
	for (int i = 1; i <= n; i++) cin >> aa[i];
	aa[n + 1] = x + 1;
	for (int i = 1; i <= n+1; i++)
	{
		if (aa[i] > x)
		{
			work();
			a.clear();
			mp.clear();
			sum.clear();
			cnt.clear();
			a.push_back(0);
			sum.push_back(0);
			cnt.push_back(0);
		}
		else a.push_back(aa[i]);
	}
	cout << res << endl;
}
signed main()
{
	std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}