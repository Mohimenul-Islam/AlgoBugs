#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int N = 5e5;
int a[N],f[N];
void solve(){
	int n;cin>>n;
	for(int i = 1;i<=n;i++)    cin>>a[i];
	f[1] = 1;f[2] = (a[1]>a[2]?3:2);
	ll ans = f[1]+f[2];
	for(int i = 3;i<=n;i++){
		if(a[i-1]>a[i])    f[i] = f[i-1]+i;
		else    f[i] = f[i-2]+i;
		ans += f[i];
	}
	cout<<ans<<endl;
}
int main(){
	int t;cin>>t;
	while(t--)    solve();
	return 0;
}