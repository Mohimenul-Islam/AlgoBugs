#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define str string
#define elif else if
#define fi(i, a, b) for (ll i = a; i < b; i++)
#define fd(i, a, b) for (ll i = a; i > b; i--)
#define input(a) for (ll _ = 0; _ < a.size(); _++) cin >> a[_]
#define iter(a, b) for (auto & b: a)
#define iterp(a) for (auto & [it1, it2]: a)
#define prinv(a) iter(a, _) {cout << _ << " ";} cout << "\n"
#define prin(a) cout << a << " "
#define print(a) cout << a << "\n"
#define prinp(a) {prin(a.first); print(a.second);}
#define nline() cout << "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mp make_pair
#define emb emplace_back
#define pushb push_back
#define pushf push_front
#define popb pop_back
#define popf pop_front
#define desc greater < > ()
#define inf LLONG_MAX
#define vll vector < ll >
#define vint vector < int >
#define vvll vector < vll >
#define pll pair < ll, ll >
#define sll set < ll >
#define vbool vector < bool >
#define vset vector < sll >
#define vstr vector < str >
#define vchar vector < char >
#define vpair vector < pair < ll, ll >>
#define map(type) map < type, ll >

const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}

bool isprime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vll genprime(ll limit) {
    vll pr;
    vbool v(limit + 1, true);
    v[0] = v[1] = false;
    for (ll i = 2; i * i <= limit; i++) {
        if (v[i]) {
            for (ll j = i * i; j <= limit; j += i) v[j] = false;
        }
    }
    fi(i, 2, limit + 1) if (v[i]) pr.emb(i);
    return pr;
}

vll genprimen(ll n) {
    vll primes;
    if (n == 0) return primes;
    ll limit = (n < 6) ? 15 : (ll)(n * log(n) + n * log(log(n)));
    vector < bool > is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= limit && primes.size() < n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i) is_prime[j] = false;
        }
    }
    return primes;
}

ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

vll modfac(ll n, ll mod) {
    vll fact(n + 1);
    fact[0] = 1;
    fi(i, 1, n + 1) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    return fact;
}

ll inv(ll a, ll m) {
    return modpow(a, m - 2, m);
}

vll imodfac(ll n, ll m1) {
    vll ifact(n + 1);
    ifact[n] = inv(1, m1);
    vll fact(n + 1);
    fact[0] = 1;
    fi(i, 1, n + 1) fact[i] = (fact[i - 1] * i) % m1;
    ifact[n] = inv(fact[n], m1);
    fd(i, n - 1, -1) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % m1;
    }
    return ifact;
}

vll primefactors(ll n, const vll & v) {
    vll f;
    iter(v, it) {
        if (it * it > n) break;
        while (n % it == 0) {
            f.emb(it);
            n /= it;
        }
    }
    if (n > 1) f.emb(n);
    return f;
}

vll divs(ll n) {
    vll d;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.emb(i);
            if (i != n / i) d.emb(n / i);
        }
    }
    sort(all(d));
    return d;
}

template < typename T > map < T, ll > counter(const vector < T > & v) {
    map < T, ll > ok;
    for (const T & x: v) {
        ok[x]++;
    }
    return ok;
}

//template <typename T>using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class disjointset {
    vll rank, parent, sz;
    public:
        disjointset(ll n) {
            rank.resize(n + 1);
            parent.resize(n + 1);
            sz.resize(n + 1, 1);
            fi(i, 0, n + 1) parent[i] = i;
        }
    ll findp(ll node) {
        return node == parent[node] ? node : parent[node] = findp(parent[node]);
    }
    void unionr(ll u, ll v) {
        ll pu = findp(u), pv = findp(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) parent[pu] = pv, sz[pv] += sz[pu];
        elif(rank[pv] < rank[pu]) parent[pv] = pu, sz[pu] += sz[pv];
        else parent[pv] = pu, sz[pu] += sz[pv], rank[pu]++;
    }
    ll getsize(ll u) {
        return sz[findp(u)];
    }
    bool iscon(ll u, ll v) {
        return findp(u) == findp(v);
    }
    vll getrank() {
        return rank;
    }
    ll countsets(ll j) {
        ll ans = 0;
        fi(i, j, parent.size() - 1 + j) if (parent[i] == i) ans++;
        return ans;
    }
};

vll vv = modfac(2*1e5,mod1);

bool dfs(vset& v, vll& v1, vll& v2, ll a,ll p){
    if(v1[a]&&v2[a]) return true;
    elif(v1[a]) return false;
    v1[a] = 1; v2[a] = 1;
    iter(v[a],it){
        if(it==p) continue;
        bool ok = dfs(v,v1,v2,it,a);
        if(ok) return true;}
    v2[a]=0; return false;
}

void solve() {
    ll n,m; cin >> n >> m; vset v(n); vll v1(n), v2(n),v5;
    fi(i,0,m){
        ll x,y; cin >> x >> y; x--; y--; 
        v[x].insert(y); v[y].insert(x);}
    vset v3 = v;
    vset v4(n);
    fi(i,0,n){
        if(v[i].size()==1){
            ll w = *(v[i].begin());
            v3[w].erase(i); v4[w].insert(i); v5.emb(i); v3[i].clear();}}
    iter(v3,it){if(it.size()>2){print(0); return;}} 
    bool ok = dfs(v,v1,v2,0,-1); if(ok){print(0); return;}
    ll ans = 2;
    if(v5.size()<=n-2) ans*=2;
    iter(v4,it){
        ans = (ans*(vv[it.size()]))%mod1;
    }
    print(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    // ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}