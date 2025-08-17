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
    int flag = 0;
    vector<int>st(n+1);
    if ( m != n - 1 ){
    	flag = 1;
	}
    for (int i = 1; i <= m; i++){
    	int u,v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
	}
	if ( flag ){
		cout << 0 << endl;
		return;
	}
	else{
		queue<int>q;
		queue<int>p;
		q.push(1);
		int ans = 1;
		while ( !q.empty() || !p.empty() ){
		while ( !q.empty() ){
		    int u = q.front();
			q.pop();
			int cnt = 0;
			st[u] = 1;
			for ( auto v : adj[u] ){
				if ( !st[v] ){
					q.push(v);
					cnt++;
				}
			}
			ans *= f[cnt];
			ans %= mod;
		}
		while ( !p.empty() ){
			int u = p.front();
			p.pop();
			int cnt = 0;
			st[u] = 1;
			for ( auto v : adj[u] ){
				if ( !st[v] ){
					p.push(v);
					cnt++;
				}
			}
			ans *= f[cnt];
			ans %= mod;
		}
		    
		}
		cout << ans * 2 % mod << endl;
	} 
}

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