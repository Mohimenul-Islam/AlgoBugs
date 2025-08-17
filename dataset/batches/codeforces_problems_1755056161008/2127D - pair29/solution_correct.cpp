#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const ll M = 1e9 + 7;
const ll mod = 998244353;
const ll N = 2e5+10;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    /*  
        
    */
    vector<ll> fact(N);
    fact[0] = fact[1] = 1;
    for(ll i=2;i<N;i++)
        fact[i] = (fact[i-1]*i)%M;
    ll tt = 1;cin>>tt;
    while(tt--){

        ll n,m;cin>>n>>m;
        vector<vector<ll>> g(n+1);
        for(ll i=0;i<m;i++){
            ll x,y;cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(m >= n){
            cout<<0<<endl;
            continue;
        }
        if(n == 2){
            cout<<2<<endl;
            continue;
        }

        bool found = false;
        for(int i=1;i<=n;i++){
            int cnt = 0;
            for(auto child : g[i]){
                if(g[child].size()>1) cnt++;
            }
            if(cnt > 2) found = true;
        }

        if(found){
            cout<<0<<endl;
            continue;
        }

        vector<ll> res(n+1);
        set<ll> s;
        for(ll i=1;i<=n;i++){
            if(g[i].size() == 1){
                s.insert(g[i][0]);
                res[g[i][0]]++;
            }
        }

        ll ans = 1;
        for(ll i=1;i<=n;i++) ans = (ans * fact[res[i]])%M;
        if(s.size() > 1) ans = (ans*2)%M;
        ans = (ans*2)%M;
        cout<<ans<<endl;

    }   
}