#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define int long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define bb begin()
#define ee end()
#define pii pair<int,int>
#define lc p<<1
#define rc p<<1|1
using namespace std;
void solve()
{//求恰好等于x的比较难，那就求小于等于x的，做个差值就得到等于x的了
	int n,s,x;cin>>n>>s>>x;
	vi a(n+1),pre(n+1);
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	auto get=[&](int nx){
		map<int,int> mp;
		mp[0]++;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>nx) mp.clear();
			res+=mp[pre[i]-s];
			mp[pre[i]]++;
		}
		return res;
	};
	cout<<get(x)-get(x-1)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}