// Enonya

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		std::vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		std::vector<int> dp(n + 1);
		dp[0] = 0, dp[1] = 1;
		if(a[1] > a[2]) dp[2] = 3;
		else dp[2] = 2;
		for(int i = 3; i <= n; ++i) {
			if(a[i - 1] > a[i]) dp[i] = dp[i - 1] + i;
			if(a[i - 2] > a[i]) dp[i] = max(dp[i], dp[i - 2] + i);
		}
		cout << accumulate(dp.begin(), dp.end(), 0) << endl;
	}

	return 0;
}
