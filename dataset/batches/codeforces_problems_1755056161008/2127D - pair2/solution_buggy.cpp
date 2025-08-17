#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<climits>
#include<algorithm>
using namespace std;
using vpll = vector<pair<long long, long long>>;
using pll = pair<long long, long long>;

using vvll = vector<vector<long long>>;

#define ll long long int
#define vll vector<long long>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define print(v)     \
    for(auto &i:v) cout<<i<<' '; \
    cout<<endl
#define all(x) x.begin(), x.end()
const long long INF = 9e18;
const long long MOD = 1e9 + 7;
const ll MAXN = 3e5;

long long fac[MAXN + 1];
void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    factorial();
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> adj(n+1);
        vector<int> inDeg(n+1);
        for(int i = 0;i<m;i++){
            int u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);

            inDeg[u]++;
            inDeg[v]++;
        }

        if(n-1 != m){
            cout<<0<<endl;
            continue;
        }

        vll leafCnt(n+1);
        for(int i = 1;i<=n;i++){
            for(auto &ngh:adj[i]){
                leafCnt[i] += (inDeg[ngh] == 1);
            }
        }

        ll ans = 2;
        ll cnt = 0;
        for(int i = 1;i<=n;i++){
            ans = (ans * fac[leafCnt[i]])%MOD;
            if(inDeg[i] >= 2) cnt++;
        }

        if(cnt>=2){
            ans = (ans*2)%MOD;
        }

        cout<<ans<<endl;









    }
    return 0;
}