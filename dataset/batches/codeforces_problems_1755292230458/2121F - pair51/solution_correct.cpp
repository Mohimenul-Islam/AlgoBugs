#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--)
    {
    	int n,s,x;cin>>n>>s>>x;
    	vector<int>v(n+1,0),pre(n+1,0);
    	map<int,int>mp;
    	for(int i=1;i<=n;i++)cin>>v[i],pre[i]=pre[i-1]+v[i];
    	int ans=0;
    	int l=1,i;
    	
		for( i=1;i<=n;i++)
		{
			if(v[i]>x)
			{
				mp.clear();
				
				l=i+1;
			}
			else if(v[i]==x)
			{
				while(l<=i)
				{
					mp[pre[l-1]]++;
					l++;
				}
			}
			ans+=(mp[pre[i]-s]);
			
			
		}
    	cout<<ans<<endl;
	}
    return 0;
}
