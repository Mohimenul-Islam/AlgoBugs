#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll constexpr MOD = 1000000007;

int factorial(ll n) {
    ll result = 1;
    
    while (n > 1) {
        result = (result * n) % MOD;
        n--;
    }
    
    return result;
}

struct graph_node {
    int degree = 0;
    vector<int> neighbors;
};

bool valid_graph(vector<graph_node> const& g, bool* visited, int const& vertex, int const& last_vertex) {
    visited[vertex] = true;
    
    int next_vertex = 0;
    
    for (int neighbor : g[vertex].neighbors) {
        if (g[neighbor].degree <= 1) continue;
        if (neighbor == last_vertex) continue;
        
        if (visited[neighbor]) return false;
        if (next_vertex != 0) return false;
        
        next_vertex = neighbor;
    }
    
    if (next_vertex == 0) return true;
    
    return valid_graph(g, visited, next_vertex, vertex);
}

bool valid_graph(vector<graph_node> const& g) {
    bool visited[g.size()] = {};
    
    int start = 0;
    int i = 1;
    
    while (i < g.size()) {
        if (g[i].degree == 1) {
            start = i;
            int next = g[i].neighbors[0];
            int leaves = 0;
            
            for (int neighbor : g[next].neighbors) {
                if (g[neighbor].degree == 1) leaves++;
            }
            
            if (leaves < g[next].degree - 1) {
                i++;
                continue;
            };
            
            start = next;
            break;
        }
        
        i++;
    }
    
    if (start == 0) return false;
    
    return valid_graph(g, visited, start, 0);
}

int get_count(vector<graph_node> const& g) {
    int n = g.size() - 1;
    if (n == 2) return 2;
    
    if (!valid_graph(g)) return 0;
    
    int non_leaf = 0;
    for (graph_node node : g) if (node.degree > 1) non_leaf++;
    
    if (non_leaf == 1) return (factorial(n - 1) << 1) % MOD;
    
    ll result = 4;
    for (graph_node node : g) {
        int leaves = 0;
        
        for (int neighbor : node.neighbors) {
            if (g[neighbor].degree == 1) leaves++;
        }
        
        result = (result * factorial(leaves)) % MOD;
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int tc_count;
    cin >> tc_count;
    
    for (int tc = 0; tc < tc_count; tc++) {
        ll n, m;
        cin >> n >> m;
        
        vector<graph_node> g(n + 1);
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            
            g[u].degree++;
            g[v].degree++;
            g[u].neighbors.push_back(v);
            g[v].neighbors.push_back(u);
        }
        
        cout << get_count(g) << "\n";
    }
    
    return 0;
}