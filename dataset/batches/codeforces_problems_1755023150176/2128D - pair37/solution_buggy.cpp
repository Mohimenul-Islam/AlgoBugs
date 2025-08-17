#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n ;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++) cin>>arr[i];
        vector<int> dp(n,0);
        dp[0]=1;
        int ans=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                dp[i]=dp[i-1]+1;
            }
            else{
                dp[i]=dp[i-1]+i+1;
            }
            ans+=dp[i];
        }
        cout << ans+1 << endl;
    }
    return 0;
}