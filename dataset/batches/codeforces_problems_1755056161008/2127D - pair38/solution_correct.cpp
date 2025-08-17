#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int> 
using namespace std;
const int maxn=2e5+10,mod=1e9+7;
int n,m,sum,ans;
bool flag;
int a[maxn],b[maxn],f[maxn],fa[maxn],fl[maxn],cnt[maxn],su[maxn];
vector<int> g1[maxn],g2[maxn];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	f[0]=1ll;
	for(int i=1;i<=2e5;i++) f[i]=f[i-1]*i%mod;
	int t;
	cin>>t;
	while(t--)
	{
		flag=sum=0,ans=1ll;
		cin>>n>>m;
		for(int i=1;i<=n;i++) fl[i]=cnt[i]=0,g1[i].clear(),g2[i].clear();
		for(int i=1;i<=m;i++)
		{
			cin>>a[i]>>b[i];
			g1[a[i]].push_back(b[i]),g1[b[i]].push_back(a[i]);
		}
		if(m>=n)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			if(g1[i].size()==n-1)
			{
				cout<<f[n-1]*2%mod<<endl;
				flag=1;
				break;
			}
		if(flag) continue;
		for(int i=1;i<=m;i++)
			if(g1[a[i]].size()!=1&&g1[b[i]].size()!=1) g2[a[i]].push_back(b[i]),g2[b[i]].push_back(a[i]);
		for(int i=1;i<=n;i++)
			if(g2[i].size()>2)
			{
				cout<<0<<endl;
				flag=1;
				break;
			}
		if(flag) continue;
		for(int i=1;i<=n;i++)
			if(g1[i].size()==1) cnt[g1[i][0]]++;
		for(int i=1;i<=n;i++)
			if(g1[i].size()>1) ans=ans*f[cnt[i]]%mod;
		cout<<ans*4%mod<<endl;
	}
}
