#include<algorithm>
#include<iostream>
using namespace std;
using i64 = long long;
const int N = 2e2 + 5;
int n, m, k, a[N], b[N], c[N];
void query(int x, int& y) { cout << "? " << x << '\n', cout.flush(), cin >> y; }
void yes(int a, int b) { cout << "! " << a << ' ' << b << '\n', cout.flush(); }
void no() { cout << "! -1\n", cout.flush(); }
void solve()
{
	cin >> n >> k; m = ((n - 1) / k + 1) * k;
	if (k == 1) return n == 2 ? yes(1, 1) : no();
	if (2 * k == n) return yes(k, k);
	for (int i = 1, j; i <= k; ++i) j = m - k + i, query(i, a[i]), query(j > n ? j - k : j, b[i]), a[k + i] = a[i], b[k + i] = b[i];
	int mis = 0;
	for (int i = 1; i <= k; ++i) if (a[i] != b[i]) mis = i;
	if (!mis) return no();
	int l = 1, r = m / k, mid, s;
	while (l + 1 < r)
	{
		mid = l + r >> 1, query((mid - 1) * k + mis, s);
		if (s == a[mis]) l = mid;
		else r = mid;
	}
	for (int i = 1, j; i <= k; ++i) j = mis + i, query((l - 1) * k + j, c[j > k ? j - k : j]), c[k + i] = c[i];
	int am, bm;
	for (am = 1; am <= k; ++am) if (a[am + mis] != c[am + mis]) break;
	for (bm = k; bm >= 1; --bm) if (b[bm + mis] != c[bm + mis]) break;
	am = min(n - k, (l - 1) * k + mis + am - 1);
	bm = max(k + 1, (l - 1) * k + mis + bm + 1);
	// cout << am << ' ' << bm << '\n';
	if (am + 1 != bm) return no();
	yes(am, n - am);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _ = 1; cin >> _;
	while (_--) solve();
}