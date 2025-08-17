#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define po pop_back

using namespace std;

const int MAXN = 2e5;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 9e18;

bool cant;
int loc[MAXN + 2];
ll fac[MAXN + 2];
vector<int> EDGE[MAXN + 2];

void dfs(int x, int prev){
    for(auto y: EDGE[x]){
        if(y == prev) continue;
        if(loc[y] == -1){
            loc[y] = 3 - loc[x];
            dfs(y, x);
        }else{
            cant = true;
        }
    }
}

void solve(){
    cant = false;
    memset(loc, -1, sizeof loc);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        EDGE[u].pb(v);
        EDGE[v].pb(u);
    }
    loc[1] = 1;
    dfs(1, 0);
    if(cant) cout << 0 << "\n";
    else{
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(auto x: EDGE[i]){
                if(EDGE[x].size() > 1) cnt++;
            }
            if(cnt >= 3){
                cout << "0\n";
                return;
            }
        }
        int satu = 0, dua = 0;
        ll ans;
        for(int i = 1; i <= n; i++){
            if(loc[i] == 1) satu++;
            else dua++;
        }
        if(satu == 1 || dua == 1) ans = 1;
        else ans = 2;
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(auto x: EDGE[i]){
                if(EDGE[x].size() == 1) cnt++;
            }
            ans = ans * fac[cnt] % MOD;
        }
        cout << ans * 2 % MOD << "\n";
    }
    for(int i = 1; i <= n; i++) EDGE[i].clear();
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fac[0] = 1;
    for(int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}