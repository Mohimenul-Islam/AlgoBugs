#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

vector<pair<ll, int>> prefix;

int search(ll k, int l, int r) {
	
	if (l > r || (l == 0 && r == 0)) {
		return 0; 
	}
	
	pair<ll, int> u = {k, l};
	pair<ll, int> v = {k, r};
	
	auto it = lower_bound(prefix.begin(), prefix.end(), u);
	
	if (it == prefix.end() || (*it).first != k) {
		return 0;
	}
	
	int x = it-prefix.begin(); 
	int y = upper_bound(prefix.begin(), prefix.end(), v)-prefix.begin(); 
	
	return y-x;
}

void solve() {
	int n; ll s; int x; cin >> n >> s >> x;
	
	vector<int> a (n+1);
	ll sum = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		prefix.push_back({sum, i});
	}
	
	sort(prefix.begin(), prefix.end()); 
	
	sum = 0;
	int l = 0, r = 0; 
	
	int cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] > x) {
			l = i;
		}
		else if (a[i] == x) {
			r = i;
		}
		
		sum += a[i]; 
		
		cnt += search(sum-s, l, r); 
	}
	
	if (x == 0 && s == 0) {
		for (int i = 1; i <= n; i++) {
			if (!a[i]) {cnt--;}
			else {break;}
		}
	}
	
	if (a[1] == x && a[1]*2 == s && a[1] != 0) {cnt--;}
	
	cout << cnt << endl;
} 

int main() {	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		prefix = {{0, 0}};
		solve();
	}
	
	return 0;
}

