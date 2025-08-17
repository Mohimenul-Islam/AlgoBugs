#include <bits/stdc++.h>
using namespace std;

//------------------------ TypeDefs ----------------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

//------------------------ Macros -----------------------------
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//------------------------ Constants --------------------------
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

// Precomputed factorials
vector<ll> fact(MAXN);

void precompute() {
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

// Detect cycle in undirected graph using DFS (0-indexed)
bool hasCycle(const vector<vll>& graph, int node, int parent, vector<bool>& visited) {
    visited[node] = true;
    
    for (auto neighbor : graph[node]) {
        // Skip the edge that led to this node
        if (neighbor == parent) continue;
        
        // If the neighbor is already visited, we found a cycle
        if (visited[neighbor]) {
            return true;
        }
        
        // Recursively check if there's a cycle starting from the neighbor
        if (hasCycle(graph, neighbor, node, visited)) {
            return true;
        }
    }
    
    return false;
}

// Wrapper function to check if the entire graph has any cycles (0-indexed)
bool detectCycle(const vector<vll>& graph, int n) {
    vector<bool> visited(n, false);
    
    // Check each component of the graph (in case it's disconnected)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(graph, i, -1, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

//------------------------ Solve + Main ------------------------
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vll> graph(n);  // 0-indexed

    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        // Convert 1-based input to 0-based
        u--; v--;
        graph[u].PB(v);
        graph[v].PB(u);
    }
    
    if(m != n-1) {
        cout << 0 << endl;
        return;
    }

    if(n == 2){
        cout << 2 << endl;
        return;
    }
    
    ll ans = 1;
    bool sym = 0;
    vll leafCounts;
    vll multinode(n, 0);  // 0-indexed

    for(int i = 0; i < n; i++){  // 0-indexed loop
        ll count = 0;
        for(auto neighbor : graph[i]){
            if(graph[neighbor].size() == 1) count++;
            else{
                for(auto j : graph[neighbor]){
                    if(j != i && graph[j].size() > 1) {
                        multinode[j] += 1;
                    }
                }
            }
        }
        if(count) leafCounts.PB(count);
        if(count == n-1) sym = 1;  // Still n-1 because we're counting the number of nodes
    }

    // for(auto i : multinode) {
    //     if(i >= 3) {
    //         cout << 0 << endl;
    //         return;
    //     }
    // }
    
    for(auto count : leafCounts) {
        ans = (ans * fact[count]) % MOD;
    }
    
    // Multipliers remain the same
    if(sym) ans = (ans * 2) % MOD;
    else ans = (ans * 4) % MOD;

    cout << ans << endl;

    
}

int32_t main() {
    fast_io;
    precompute();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}