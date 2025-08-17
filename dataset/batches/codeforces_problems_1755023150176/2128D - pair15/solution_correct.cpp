#include <bits/stdc++.h>
using namespace std;

// =============================
// ⚡ Competitive Programming Template
// =============================

// Fast IO
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// Common shortcuts
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<long long>;

// Loop macros
#define fo(i, n) for (int i = 0; i < (n); ++i)
#define Fo(i, a, b) for (int i = (a); i < (b); ++i)

// Constants
const ll INF = 1e18;
const int MOD = 1e9+7;
const ld EPS = 1e-9;

// Debug macro
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << (x) << '\n';
#else
    #define debug(x)
#endif

// Modular exponentiation
ll modpow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// GCD & LCM
ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

// Solve function
void solve() {
    int n;
    cin >> n;
    vll arr(n);
    fo(i, n) cin >> arr[i];
    vll dp(n, 0);

    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (arr[i] < arr[i - 1]) {
            dp[i] += i;
        }
    }
    ll ans = 0;
    fo(i,n) {
        ans += dp[i];
    }
    cout << ans << "\n";


}

// =============================
int main() {
    FAST_IO;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t; // Uncomment for multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
