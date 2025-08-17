#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
vector<int> fact(200001, 1);
void precompute(){
    for(int i=2; i<200001; i++){
        fact[i] = fact[i-1] * i % mod;
    }
}

int solve(int n, int m){
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n == 1) return 0;
    if(n == 2) return 2;
    if(m != n-1) return 0;

    int ans = 1, internal = 0;
    for(int i=0; i<n; i++){
        if(adj[i].size() == 1) continue;
        internal++;

        int leaf = 0, cnt = 0;
        for(int j : adj[i]){
            if(adj[j].size() == 1) leaf++;
            else cnt++;

            if(cnt > 2) return 0;
        }
        ans *= fact[leaf]%mod;
    }

    if(internal == 1) return 2*ans%mod;
    return 4*ans % mod;
}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        cout << solve(n, m) << "\n";
    }
}