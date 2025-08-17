#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(x) -> number of elements strictly less than x
// find_by_order(i) -> element present in the ith index
#define fast_io()\
    ios_base::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);
// #define ONLINE_JUDGE
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define vll vector<ll>
#define vld vector<ld>
#define sll set<ll>
#define pll pair<ll, ll>
#define mll map<ll,ll>
#define vpll vector<pll>
#define point(n) fixed << setprecision(n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define trav(a, x) for (auto &a : x)
#define MOD 1000000007ll
template <typename T>
void read_vector(vector<T> &v){for (auto &x : v)cin >> x;}
template <typename T>
void print_vector(const vector<T> &v){for (const auto &x : v)cout << x << ' ';cout << '\n';}
template <typename T>
void print_vector(vector<vector<T>> &v) {for(auto &i: v) {for(auto &ele :i) cout << ele << ' ';cout << '\n';}}
template <typename T1, typename T2>
void read_vector_pair(vector<pair<T1,T2>> &v){for (auto &x : v)cin >> x.fi >> x.se;}
template <typename T1, typename T2>
void print_vector_pair(const vector<pair<T1, T2>> &v){for (const auto &x : v)cout << "{" << x.fi << ", " << x.se << "} ";cout << '\n';}
ll gcd(ll a, ll b){return b ? gcd((b), (a) % (b)) : a;}
ll lcm(ll a, ll b){return (a / gcd(a, b)) * b;}
vll factorial(ll n, ll m = MOD){vll v(n + 1, 1); rep(i, 1, n + 1) v[i] = (v[i - 1] * i) % m; return v;}
ll mod_exp(ll base, ll exp, ll mod){
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
ll nCr(const vll &f, ll n, ll r, ll m = MOD) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    return ((f[n] * mod_exp(f[r], m - 2, m)) % m * mod_exp(f[n - r], m - 2, m)) % m;
}
bool isComposite(ll n){
    if (n <= 3) return false;
    if (n % 2 == 0 || n % 3 == 0) return true;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return true;
    return false;
}
vpll primeFactor(ll n) {
    vpll factors; ll count = 0;
    while (n % 2 == 0) {
        n /= 2; count++;
    }
    if(count) factors.pb({2, count});
    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            n /= i;
        ll u, v, x; 
            count++;
        }
        if(count) factors.pb({i, count});
    }
    if(n > 2) factors.pb({n, 1});
    return factors;
}
vll find_factors(ll n) {
    vll factors;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    }
    sort(all(factors));
    return factors;
}
vll SieveOfEratosthenes(int n){
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }       
    vll ans;
    for(int i = 2; i <= n; i++) {
        if(!prime[i])
            continue;
        ans.pb(i);
    }
    return ans;
}

vll fact = factorial(2e5);
void solve() {
    ll n; cin >> n;
    ll m; cin >> m;
    vector<vll> al(n);
    vll vis(n, 0);
    rep(i, 0, m) {
        ll u, v; cin >> u >> v;
        u--, v--;
        al[u].pb(v);
        al[v].pb(u);
        vis[u] = vis[v] = 1;
    }

    bool pos = true;
    rep(i, 0, n) {
        ll cnt = 0;
        trav(u, al[i]) cnt += (al[u].size() > 1);
        if(cnt <= 2)
            continue;
        pos = false;
        break;
    }

    if(m >= n || (accumulate(all(vis), 0ll) != n) || !pos) {
        cout << "0\n";
        return;
    }

    // calculate
    vis = vll(n, 0);
    ll non_leaf = 0;
    rep(i, 0, n) {
        if(al[i].size() == 1)
            continue;
        non_leaf = i;
    }
    auto dfs = [&](ll u, auto &&dfs) -> ll {
        ll cnt = 1, more = 0, one = 0;
        vis[u] = 1;
        trav(node, al[u]) {
            if(vis[node])
                continue;
            (al[node].size() == 1 ? one++ : more++);
            cnt = (cnt * dfs(node, dfs)) % MOD;
        }
        cnt = (cnt * fact[one] * (more ? 2 : 1)) % MOD;
        return cnt;
    };
    cout << (2 * dfs(non_leaf, dfs)) % MOD << '\n';
}

int main(){
    fast_io();
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif  
    ll t = 1;  
    cin >> t;  
    rep(i, 1, t + 1)
        solve();
    return 0;
}