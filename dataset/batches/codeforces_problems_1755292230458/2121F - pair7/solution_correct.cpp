#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
	int n; ll s; int x; cin >> n >> s >> x; 
	
	vector<int> a (n+1); 
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	
	vector<ll> prefix (n+1); 
	map<ll, int> cnt; 
	
	int lef = 1; 
	ll ans = 0; 
	
	for (int r = 1; r <= n; r++) {
		prefix[r] = prefix[r-1]+a[r]; 
		
		if (a[r] > x) {cnt.clear(); lef = r+1;}
		else if (a[r] == x) {
			while (lef <= r) {
				cnt[prefix[lef-1]]++;
				lef++;
			}
		}
		
		ans += cnt[prefix[r]-s]; 
	}
	
	cout << ans << endl;
	
} 

int main() {	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}

