#include <bits/stdc++.h>
using namespace std;

//debug
#ifdef DEBUG
#define fastio()
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define debug(...)
#endif

#define cif(x) for(auto &it : x) cin >> it
#define cof(x) for(auto &it : x) cout << it << " "
#define all(x) x.begin(), x.end()
#define ll long long
#define pll pair<long long, long long>
#define pi pair<int, int>
#define vll vector<long long>
#define vi vector<int>
#define sll set<long long>
#define usll unordered_set<long long>
#define si set<int>
#define usi unordered_set<int>
#define mll map<long long, long long>
#define umll unordered_map<long long, long long>
#define umi unordered_map<int, int>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int MOD = 998244353;
const double EPS = 1e-9;
const ll NEG_INF = LLONG_MIN / 2;
const int MAX = 10001;
const array<int, 4> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};

int n, m, i, j, k, p, q, u, v;
string s;
bool f, f1, f2;
vector<bool> primes;
/*bool joint[MAX];
vi g[MAX];
int timeDfs = 0, bridge = 0;
int low[MAX], num[MAX], tail[MAX];

void dfs(int u, int pre) {
    int tmp = 0;
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]){
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) bridge++;
            tmp++;
            if (u == pre) {
                if (tmp > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
    tail[u] = timeDfs;
}*/

void prime_n(int n) {
    primes.assign(n + 1, true);
    primes[0] = primes[1] = false;	
    for (i = 2; i * i <= n; i++)
        if (primes[i]) 
            for (j = i * i; j <= n; j += i) 
                primes[j] = false;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        vi a(n); cif(a);
        ll sum = n*(n+1)*(n+2)*1LL/6;
        for (i = 0; i < n - 1; i++) {
            if (a[i] < a[i + 1]) {
                sum -= 1LL * (i + 1) * (n - i - 1);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}