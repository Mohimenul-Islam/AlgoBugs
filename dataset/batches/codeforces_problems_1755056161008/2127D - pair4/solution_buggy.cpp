#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) fr(i,0,n)
#define F first
#define S second
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 5;

// ---------- Utility Functions ----------
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int binpow(int a, int b, int mod = MOD) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int modinv(int a, int mod = MOD) {
    return binpow(a, mod - 2, mod);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    return is_prime;
}

void debug_vec(const vi& v) {
    for (auto x : v) cout << x << ' '; cout << endl;
}
int M = 1000000007;


// BFS cycle detection for undirected graph
bool hasCycleUndirectedBFS(int V, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(V);
    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            queue<pair<int,int>> q;
            q.push({i, -1});
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front().first;
                int p = q.front().second;
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push({v, u});
                    } else if (v != p) {
                        return true; // Found a cycle
                    }
                }
            }
        }
    }
    return false;
}

int fac(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans%=M;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    vector<pii> e(m);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        e[i] = {u, v};
    }

    // Check for cycle
    if (hasCycleUndirectedBFS(n, e)) {
        cout << 0 << "\n";
        return;
    }

    // Identify leaves
    vi leaf(n, 0);
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            leaf[i] = 1;
        }
    }

    // Check "non-leaf neighbor" condition
    for (int i = 0; i < n; i++) {
        int nlc = 0;
        for (auto j : g[i]) {
            if (leaf[j] == 0) nlc++;
        }
        if (nlc >= 3) {
            cout << 0 << "\n";
            return;
        }
    }

    int lc = n - accumulate(leaf.begin(), leaf.end(), 0);

    // I will remove the leafs now to have it better here.
    vi deg(n,0);
    for(int i=0;i<n;i++){
        for(auto j:g[i]){
            if(leaf[j]==1){
                deg[i]++;
            }
        }
        // deg[i]+=g[i].size();
    }

    if (lc == 0) {
        cout << 2 << "\n";
    } else if (lc == 1) {
        cout << 2 * fac(n - 1) << "\n";
    } else {
        int ans = 4;
        for (int i = 0; i < n; i++) {
                ans *= fac(deg[i]);
                ans%=M;
        }
        cout << ans << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
} 