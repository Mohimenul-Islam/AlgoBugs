#include<bits/stdc++.h>
using namespace std;
int T , n;
int a[500005];
int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		int ans = n;
		for(int i = 1 ; i < n ; i++){
			if(a[i] > a[i + 1]) ans += i * (n - i + 1);
			else ans += i;
		}
		cout << ans << '\n';
	}
	return 0;
}