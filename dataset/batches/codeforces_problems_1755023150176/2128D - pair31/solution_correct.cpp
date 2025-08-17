#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono;
 
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvl;
typedef vector<pair<long long, long long>> vpair;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef long double lld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
#define f(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define nl "\n"
#define ss second
#define ff first
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(arr) arr.begin(), arr.end()
#define inf INT64_MAX

const int M = 1000000007;
const int M2 = 998244353;

#ifndef ONLINE_JUDGE
    #define debug(x) { cerr << "[ " << #x << " ] = "; _print(x); cerr << endl; } 
#else 
    #define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(ll t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(bool t) { cerr << t; }   
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T> void _print(vector<T> v1) { cerr << "[ "; for(T i: v1) { _print(i); cerr << ", "; } cerr << " ]\n"; }
template <class T, class V> void _print(map<T, V> mp1) { cerr << "[ \n"; for(auto i: mp1) cerr << i.ff << " : " << i.ss << endl; cerr << "]\n";}
template <class T> void _print(set<T> s1) { cerr << "[ "; for(auto i: s1) cerr << i << ", "; cerr << "]" << endl;}
template <class T> void _print(multiset<T> s1) { cerr << "[ "; for(auto i: s1) cerr << i << ", "; cerr << "]" << endl;}
template <class T, class V> void _print(pair<T, V> p) { cerr << "[ " << p.ff << " : " << p.ss << " ] " << endl; };
template <class T> void _print(priority_queue<T> pq) { cerr << "[ "; while(!pq.empty()) { cerr << pq.top() << " "; pq.pop(); }; cerr << " ]\n"; }
template <class T, class V> void _print(priority_queue<pair<T, V>> pq) { cerr << "[\n"; while(!pq.empty()) { cerr << pq.top().ff << ", " << pq.top().ss << "\n"; pq.pop(); }; cerr << "]\n"; }

template <class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 
random_device rd;
mt19937 rng(rd());
ll get_random(ll l, ll r) {
    uniform_int_distribution<ll> dist(l, r);
    return dist(rng);
}

ll binpow(ll a, ll b) {
    // a ^ b
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }

    return res % M;
}

void solve() {
    int n;
    cin >> n;
    vll a(n);
    f(i, n) cin >> a[i];

    ll total = 0;
    f(i, n) {
        total += (ll)(n - i) * (ll)(n - i + 1) / 2;
    }

    f(i, n - 1) {
        if(a[i] < a[i + 1]) {
            total -= 1LL * (i + 1) * (n - i - 1);
        }
    }

    cout << total << nl;
}

int main() {
    fastIO;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}