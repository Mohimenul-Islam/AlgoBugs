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
const int N=2e5+10;
int f[N][33], Log2[N];
void build(int n,vi &b) {
    for (int i = 2; i <= n; ++i)
        Log2[i] = Log2[i / 2] + 1;
    for (int i = 1; i <= n; i++)
        f[i][0] = b[i];
    for (int i = 1; i <= 32; ++i)
        for (int j = 1; j + (1ll << i) - 1 <= n; ++j)
            f[j][i] = max(f[j][i - 1], f[j + (1ll << (i - 1))][i - 1]);
}
int query(int L, int R) {
    int p = Log2[R - L + 1];
    return max(f[L][p], f[R - (1 << p) + 1][p]);
}
void solve()
{
	int n,s,x;cin>>n>>s>>x;
	vi a(n+1),pre(n+1);
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	build(n,a);
	int res=0;
	map<int,vi> cnt;
	cnt[0].pb(0);
	for(int i=1;i<=n;i++)
	{
		int now=pre[i]-s;
		int m=cnt[now].size();
		for(int j=m-1;j>=0;j--)
		{
			int t=cnt[now][j];
			int p=query(t+1,i);
			if(p==x) res++;
			else if(p>x) break;
		}
		cnt[pre[i]].pb(i);
	}
	cout<<res<<endl;
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