#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,a[N],f[N],to[N],g[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		f[1]=1,f[2]=(a[2]<a[1]?3:2);
		for(int i=3;i<=n;i++)
		{
			if(min(a[i-1],a[i-2])<a[i])
			{
				if(a[i-1]>a[i-2]) f[i]=f[i-1]+i;
				else f[i]=f[i-2]+i;
			}
			else
			{
				if(a[i-1]<a[i-2]) f[i]=f[i-1]+i;
				else f[i]=f[i-2]+i+1;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++) ans+=f[i];
		printf("%lld\n",ans);
	}
	return 0;
}