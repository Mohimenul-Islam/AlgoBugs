#include <iostream>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int MAX = 2e5+4;
vector<ll> fact;

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> deg(n+1);
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if (m!=n-1) {
        cout << 0 << endl;
        return;
    }
    ll ans = 1;
    int n_non_leaf = 0;
    for (int u = 1; u <= n; ++u) {
        int leaf = 0;
        for (int v : g[u]) {
            if (deg[v]==1) {
                leaf++;
            }
        }
        if (leaf<deg[u]-2) {
            cout << 0 << endl;
            return;
        }
        ans = (ans*fact[leaf])%mod;
        if (deg[u]>1) {
            n_non_leaf++;
        }
    }
    ans = (ans*2)%mod;
    if (n_non_leaf>1) {
        ans = (ans*2)%mod;
    }
    cout << ans << endl;
}

int main()
{
    fact.resize(MAX);
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = (fact[i-1]*i)%mod;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

