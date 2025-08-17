#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<'\n';
#define int long long

void solve() {
	int n, m; cin >> n >> m;
	vector<int> v[n + 1];
	int ans = 2; // 第一个结点可以放在任意一侧
	for(int i = 1; i <= m; i ++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	if(m != n - 1) {
		cout << 0 << '\n';
		return;
	}
	
	function<int(int, int, int)> dfs = [&](int cur, int fa, int s){
		int ch_num = 0, non_leaf = 0;
		
		for(int it : v[cur]) {
			if(it == fa) continue;
			non_leaf += dfs(it, cur, 1);
			ch_num ++;
		}
		if(ch_num == 0) return 0;
		
		// 非叶子结点只能放在最左/右位置，s 表示可放侧，仅对于第二层结点是 2,其余是 1. 
		if(non_leaf > s) {
			ans = 0;
			return 1;
		}
		
		if(ch_num <= s) {
			ans *= ch_num;
		} else {
			for(int i = 1; i <= ch_num - non_leaf; i ++) {
				ans *= i;
			}
			if(non_leaf) ans *= s;
		}
		// 计算中合并了一些情况
		
		return 1;
	};
	
	int idx = 0;
	for(int i = 1; i <= n; i ++) {
		if(v[i].size() > 1) {
			idx = i;
		}
	}
	
	dfs(idx, idx, 2);
	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}