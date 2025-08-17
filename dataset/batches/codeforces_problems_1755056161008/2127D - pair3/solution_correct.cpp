#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const ll modd = 998244353;


ll modInverse(ll a, ll m) {
    ll res = 1, p = m - 2ll;
    while (p) {
        if (p & 1ll) res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1ll;
    }
    return res;
}

vector<ll> fact, invFact;

void f(ll maxN) {
    fact.resize(maxN + 1);
    invFact.resize(maxN + 1);
    fact[0] = invFact[0] = 1;

    for (ll i = 1; i <= maxN; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    for (ll i = 0; i <= maxN; ++i) {
        invFact[i] = modInverse(fact[i], mod);
    }
}

ll p(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * invFact[n - r] % mod;
}

ll c(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}


void solve() {    
    ll n, m;
    cin>>n>>m;

    vector<ll>adj[n + 1];
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll>c(n + 1, -1);
    queue<array<ll, 2>>q;
    q.push({1, 0});
    c[0] = 1;
    c[1] = 0;
    vector<bool>visited(n + 1, 0);
    ll ans = 1;
    bool flag = 1;
    while(!q.empty()) {
        ll n = q.size();
        for(ll i = 0; i < n; i++) {
            auto [node, par] = q.front();
            visited[node] = 1;
            q.pop();
            ll a = 0, b = 0;

            for(auto &y : adj[node]) {
                if(adj[y].size() == 1) b++;
                else a++; 
                if(y == par) continue;
                if(c[y] == c[node] || visited[y]) {
                    cout<<0<<"\n";
                    dbg(0);
                    return;
                }
                
                c[y] = 1 - c[node];
                q.push({y, node});
            }
            if(a > 2) {
                cout<<0<<"\n";
                dbg(0);
                return;
            }
            ans *= fact[b];
            ans %= mod;
            
            if((a == 2 || (a == 1 && b > 0)) && flag) ans *= 2, flag = 0;

            ans %= mod;
        }
    }
    ans *= 2;

    ans %= mod;

    cout<<ans<<"\n";
    dbg(ans);



}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    f(2e5 + 10);
    
    while (t--) solve();

    return 0;
}
