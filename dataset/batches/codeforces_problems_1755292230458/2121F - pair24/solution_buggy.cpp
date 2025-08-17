#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
int T;
int n,x;
long long s;
int a[MAXN];
long long p[MAXN];
int ans;
int f;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans=0;;
		scanf("%d %lld %d",&n,&s,&x);
		map<long long,int> cnt;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			p[i]=p[i-1]+a[i];
		}
		f=1;
		for (int i=1;i<=n;i++)
		{
			if (a[i]>x) {cnt.clear();f=i+1;}
			else
			{
				if (a[i]==x)
				{//确保当前区间最小值为x的时候，把该区间前缀标记 
					while (f<=i)
					{
						cnt[p[f-1]]++;
						f++;
					}
				}
			}
			ans+=cnt[p[i]-s];
		}
		printf("%d\n",ans);
	}
	return 0;
}