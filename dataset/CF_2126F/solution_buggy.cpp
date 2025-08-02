#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, q; 
        cin >> n >> q;
        vector<int> a(n); 
        for(auto &x : a) 
            cin >> x;

        vector<vector<int>> adj(n); 
        map<pair<int,int>, int> edge;
        vector<int> isheavy(n);
        vector<vector<int>> heavy_adj(n);
        vector<map<int, ll>> col_cnt(n); 
        ll tot = 0;
        for(int i = 0; i < n - 1; i++) {
            int u, v, c; 
            cin >> u >> v >> c; 
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edge[{min(u,v), max(u,v)}] = c;
            tot += 2 * c;
        }
        int B = sqrt(n);
        for(int i = 0; i < n; i++) {
            if((int)adj[i].size() > B) {
                isheavy[i] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(auto &y : adj[i]) {
                if(isheavy[y]) {
                    heavy_adj[i].push_back(y);
                }
                if(isheavy[i]) {
                    col_cnt[i][a[y]] += edge[{min(i,y), max(i,y)}];
                }
                if(a[i] == a[y]) {
                    tot -= edge[{min(i,y), max(i,y)}];
                }
            }
        }
        tot /= 2;
        while(q--) {
            int i, x; 
            cin >> i >> x; 
            i--;
            if(isheavy[i]) {
                tot += col_cnt[i][a[i]];
                tot -= col_cnt[i][x];
            }
            else {
                for(auto y : adj[i]) {
                    if(a[y] == a[i]) tot += edge[{min(y,i), max(y,i)}];
                    if(a[y] == x) tot -= edge[{min(y,i), max(y,i)}];
                }
            }

            for(auto y : heavy_adj[i]) {
                col_cnt[y][a[i]] -= edge[{min(y,i), max(y,i)}];
                col_cnt[y][x] += edge[{min(y,i), max(y,i)}];
            }

            a[i] = x;
            cout << tot << "\n";
        }
    }

    return 0;
}