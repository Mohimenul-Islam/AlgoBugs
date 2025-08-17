#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using lll=__int128;

const ll MOD=1e9+7;
const int MAXN=2e5+5;
ll fact[MAXN]={1};

void solve() {
    int n,m;
	cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(m>=n) {
        cout<<"0\n";
        return;
    }

    if(n==2) {
        cout<<"2\n";
        return;
    }

    vector<pair<int,int>> ppt(n+1,{0,0}); //顶点性质，顶点的度
    for(int i=1;i<=n;i++) {
        if(graph[i].size()==1) {
            ppt[i].first=-1;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(graph[i].size()==1) continue;
        else cnt++;
        ppt[i].second=graph[i].size();
        for(int to:graph[i]) {
            if(ppt[to].first!=-1) {
                ppt[i].first++;
                if(ppt[i].first>=3) {
                    cout<<"0\n";
                    return;
                }
            }
        }
    }

    ll ans;
    if(cnt==1) {
        ans=2;
    }
    else {
        ans=4;
    }
    for(int i=1;i<=n;i++) {
        if(ppt[i].first!=-1) {
            ans=(ans*fact[ppt[i].second-ppt[i].first])%MOD;
        }
    }
    cout<<ans<<'\n';

    // vector<ll> sz;
    // for(int i=1;i<=n;i++) {
    //     if(graph[i].size()>1) {
    //         sz.push_back(graph[i].size()-1);
    //     }
    // }
    // if(sz.size()==1) {
    //     ll ans=((ll)2*fact[sz[0]+(ll)1])%MOD;
    //     cout<<ans<<'\n';
    //     return;
    // }

    // ll ans=4;
    // for(int i=0;i<sz.size();i++) {
    //     ans=(ans*fact[sz[i]])%MOD;
    // }
    // cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);

    for(ll i=1;i<=MAXN;i++) {
        fact[i]=(fact[i-1]*i)%MOD;
    }
    
    int t;cin>>t;
    while(t--) solve();
    
    return 0;
}
