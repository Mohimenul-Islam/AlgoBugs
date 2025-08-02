#include<bits/stdc++.h>
using namespace std;
bool f(vector<int>a, int ma, int l, int r, int c) {//最多删c个ma的情况下能不能变成回文
	//cout << l << " " << r << " " << ma << " " << c << endl;
	if (l >= r)return true;
	bool ans = false;
	if (a[r] == a[l]) {
		ans |= f(a, ma, l + 1, r - 1, c);
	}
	else {
		if (a[r] == ma && c > 0) {
			ans |= f(a, ma, l, r - 1, c - 1);
		}
		if (a[l] == ma && c > 0) {
			ans |= f(a, ma, l + 1, r, c - 1);
		}
	}
	return ans;
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n + 1);
	vector<array<int, 2>>b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i][0] = a[i];
		b[i][1] = i;
	}
	if (k == 1) {
		cout << "YES\n";
		return;
	}
	sort(b.begin() + 1, b.end(), [&](auto x, auto y) {
		return x[0] < y[0];
		});
	vector<int>pos;//记录最小的k-1个的位置
	for (int i = 1; i <= k - 1; i++) {
		pos.push_back(b[i][1]);
	}
	int ma = a[pos.back()];
	vector<int>an;
	for (int i = 1; i <= n; i++) {
		if (a[i] == ma)an.push_back(i);
	}
	int cnt = 0;
	for (int i = 0; i < pos.size(); i++) {
		if (a[pos[i]] != ma) {
			cnt++;
			an.push_back(pos[i]);
		}
	}
	sort(an.begin(), an.end(), [&](auto x, auto y) {
		return x < y;
		});
	for (int i = 0; i < an.size(); i++) {
		an[i] = a[an[i]];
		//cout << an[i] << " ";
	}//cout << endl;
	//cout << ma << " " << int(an.size()) - k + 1 << endl;
	if (f(an, ma, 0, an.size() - 1, int(an.size()) - k + 1)) {
		cout << "YES\n";
	}
	else cout << "NO\n";

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
