#include<bits/stdc++.h>
using namespace std;
int main(){
     int t; cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        
        vector<int>dp(n,0);
        dp[0]=1;
        int ans=1;
        if(a[1]<a[0])  dp[1]=3;
        else dp[1]=2;
        ans+=dp[1];
        for(int i=2;i<n;i++){
            if(a[i]<a[i-1]) dp[i]=dp[i-1]+i+1;
            else dp[i]=dp[i-2]+i+1;
        
            ans+=dp[i];
        }
        cout<<ans<<endl;
    }
}