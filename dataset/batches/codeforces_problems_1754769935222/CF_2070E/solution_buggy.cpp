#include <bits/stdc++.h>
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int a, int b) {
	return rng() % (b - a + 1) + a;
}

string to_string(string s) {
	return s;
}
template <typename T> string to_string(T v) {
	bool first = true;
	string res = "[";
	for (const auto &x : v) {
		if (!first)
			res += ", ";
		first = false;
		res += to_string(x);
	}
	res += "]";
	return res;
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << to_string(H);
	dbg_out(T...);
}

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;
template<class T> inline void chkmax(T &x, T y) { if (x < y) x = y; }
template<class T> inline void chkmin(T &x, T y) { if (x > y) x = y; }

struct BinaryIndexedTree {
	int n;
	vector<int> arr;
	BinaryIndexedTree(int n_ = 0) {
		init(n_);
	}
	void init(int n_) {
		n = n_;
		arr.assign(n + 1, 0);
	};
	void add(int x, int add) {
		x += 1;
		for( ; x <= n; x += x & -x) arr[x] += add;
	};
	int get(int x) {
		int rlt = 0;
		for( ; x > 0; x -= x & -x) rlt += arr[x];
		return rlt;
	}
}bt[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

//	freopen("in.txt", "r", stdin);
	
	int n; cin >> n;
	string s; cin >> s;
	for(int i = 0; i < 3; i ++) bt[i].init(n << 1);
	
	auto add = [&](int x, int y) -> void {
		int d = y - x + n;
		bt[y % 3].add(d, 1);
	};
	auto get = [&](int x, int y) -> int {
		int d = y - x + n, tot = 0;
		for(int i = 0; i < 3; i ++) {
			int j = ((y % 3) - i + 3) % 3;
			if(j == 0) tot += bt[i].get(d);
			if(j == 1) tot += bt[i].get(d - 1);
			if(j == 2) tot += bt[i].get(d + 2);
		}
		return tot;
	};
	
	long long ans = 0;
	int cnt[2] = {0};
	add(0, 0);
	for(int i = 1; i <= n; i ++) {
		if(s[i - 1] == '0') cnt[0] ++;
		else cnt[1] ++;
		
		ans += get(3 * cnt[1], cnt[0]);
		add(3 * cnt[1], cnt[0]);
	}
	
	cout << ans << endl;

	return 0;
}
