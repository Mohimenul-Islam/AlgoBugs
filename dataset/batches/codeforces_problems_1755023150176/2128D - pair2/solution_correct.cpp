#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	// your code goes her
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	    cin>>v[i];
	    vector<int> dp(n,1);
	    for(int i=1;i<n;i++)
	    {
	        dp[i]+=dp[i-1];
	        if(v[i]<v[i-1])
	        dp[i]+=i;
	    }
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        ans+=dp[i];
	    }
	    cout<<ans<<endl;
	}

}
