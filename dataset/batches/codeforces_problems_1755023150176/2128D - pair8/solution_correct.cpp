#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template <typename T, typename... Args>
void dbg(const T &first, Args... args) {
	cout << first;
	if constexpr (sizeof...(args)) {
		cout.put(' ');
		dbg(args...);
	} else {
		cout << endl;
	}
}

constexpr int N = 500000 + 1;

int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 1; i < n; ++i) if (a[i] > a[i + 1]) {
		ans += (ll)i * (n - i);
	}
	cout << ans + ((ll)n * (n + 1) >> 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef jiji
	freopen("../IO/input.txt", "r", stdin);
#endif

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}