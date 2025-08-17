#include <bits/stdc++.h>
using namespace std;
int T,n,a[200001],b[200001],c[200001],d[200001],cnt,ans,maxx,maxn;
int main()
{
    cin>>T;
    while(T--)
	{
		ans=0;
        c[0]=99999999;
		maxx=99999999;
		maxn=99999999;
        cin>>n;
        d[n+1]=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) c[i]=min(c[i-1],b[i]);
        for(int i=n;i>=1;i--) d[i]=max(d[i+1],a[i]);
        for(int i=1;i<=n;i++)
		{
            if(maxn>a[i]) maxx=maxn,maxn=a[i];
            else if(maxx>a[i]) maxx=a[i];
            if(min(max(d[i+1],maxn),maxx)<c[n-i+1]) break;
            ans=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
