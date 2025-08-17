#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef pair<int, int>PII;
const int N=1e6+10,mod=1e9+7;
int t,n,m,k,d[N],pre[N],ans,sum,id1,id2,x,f;
vector<int>v[N];
bool st[N];
int fact[N];
void dfs(int u,int fa)
{
	d[u]=d[fa]+1;
	for(auto k:v[u])
	{
		if(k==fa)continue;
		pre[k]=u;
		dfs(k,u);
	}
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(int)fact[i-1]*i%mod;
    }
    cin>>t;
    while(t--)
    {
    	cin>>n>>m;f=0;
    	if(m!=n-1)f=1;
    	for(int i=1;i<=n;i++)d[i]=0,pre[i]=0,st[i]=false,v[i].clear();
    	while(m--)
    	{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(f)
		{
			cout<<0<<endl;
			continue;
		}
		ans=1;
		sum=id1=id2=0;
		dfs(1,0);
		for(int i=1;i<=n;i++)
		{
			if(d[i]>sum)
			{
				sum=d[i];
				id1=i;
			}
		}
		for(int i=1;i<=n;i++)d[i]=0;
		pre[id1]=0;sum=0;
		dfs(id1,0);
		for(int i=1;i<=n;i++)
		{
			if(d[i]>sum)
			{
				sum=d[i];
				id2=i;
			}
		}
		int temp=id2,s1=0,s2=0;
		while(temp)
		{
			s1=s2=0;
			for(auto k:v[temp])
			{
				if(v[k].size()==1)s1++;
				else s2++;
			}
			if(s2>2)
			{
				f=1;
				break;
			}
			if(s2&&s1)f=2;
			ans%=mod;
			if(s1)ans=(1LL*ans*fact[s1]%mod)%mod;
			ans%=mod;
			//cout<<temp<<" "<<ans<<endl;
			temp=pre[temp];
		}
		if(f==1)cout<<0<<endl;
		else
		{
			if(f==2)
			{
				ans=(1LL*ans*fact[2]%mod)%mod;
				ans%=mod;
			}
			cout<<(1LL*ans*2)%mod<<endl;
		}
	}
}