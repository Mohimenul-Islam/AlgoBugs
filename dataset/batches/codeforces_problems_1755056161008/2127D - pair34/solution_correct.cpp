#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int f[N];
void init(){
	f[1] = 1;
	f[0] = 1;
	for (int i = 1; i <= N; i++){
		f[i] = f[i-1]*i % mod;
	}
}
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1,vector<int>());
    for (int i = 1; i <= m; i++){
    	int u,v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
	}
	int ans = 2;
	if ( m >= n ){
		cout << 0 << endl;
		return;
	}
	int cnt = 0;
	for (int u = 1; u <= n; u++){
		if ( adj[u].size() > 1 ) {
			int x = 0; // 记录该节点下一位为叶子节点的个数 
			for (int v : adj[u] ){ 
				if ( adj[v].size() == 1 ) x++;
			}
			if ( x >= adj[u].size() - 2 ) ans = ans*f[x] % mod;// 只能有一个分支以及多个叶子节点 
			else{
				cout << 0 << endl;
				return;
			}
		}
		else{
			cnt++;
		}
	}
	if ( cnt == n - 1 || m == 1 ) cnt = 1;
	else cnt = 2;
	cout << ans*cnt % mod << endl;
}
// 每个节点都连两个节点，有两种摆法？ 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}