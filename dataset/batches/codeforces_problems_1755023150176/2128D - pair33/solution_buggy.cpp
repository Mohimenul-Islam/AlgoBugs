#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n+1,0);
		for(int i = 1;i<=n;i++) cin >> a[i];
		vector<int> dp(n+1,0);
		dp[1] = 1;
		long long ans = dp[1];
		for(int i = 2;i<=n;i++){
			if(a[i] < a[i-1]) dp[i] = dp[i-1] + i;
			else dp[i] = dp[i-1] + 1;
			ans += dp[i];
		}
		
		cout << ans << endl;
	}
	return 0;
}