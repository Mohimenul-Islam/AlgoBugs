#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

ll n,m,t,ans,x,y,e,u;

ll fact[200005];

vector <ll> edg[200005];

bool leaf[200005];

ll Mod = 1e9 + 7;

string s;

bool fg;

pair <ll,ll> pr,inf[200005];

ll cnt;

void cot(ll a, ll par){
    for(int i = 0; i < edg[a].size(); i++){
        if(edg[a][i] == par) continue;
        cot(edg[a][i],a);
    }
    cnt = 0;
    for(int i = 0; i < edg[a].size(); i++){
        if(edg[a][i] == par) continue;
        if(leaf[edg[a][i]] == true)
            cnt++;
    }
    inf[a] = {cnt,edg[a].size() - 1 - cnt};
}

void rn(ll a, ll par){
    if(a == x){
        if(inf[a].s > 2){
            fg = true;
            return;
        } else if(inf[a].s <= 2 && inf[a].s >= 1){
            ans *= fact[inf[a].f] * 2;
        } else {
            ans *= fact[inf[a].f];
        }
    } else {
        if(inf[a].s >= 2){
            fg = true;
            return;
        } else {
            ans *= fact[inf[a].f];
        }
    }
    ans %= Mod;
    pr = {0,0};
    for(int i = 0; i < edg[a].size(); i++){
        if(edg[a][i] == par) continue;
        if(leaf[edg[a][i]] == false){
            if(pr.f == 0)
            pr.f = edg[a][i];
            else pr.s = edg[a][i];
        }
    }
    int x = pr.f;
    int y = pr.s;
    if(x != 0)
    rn(x,a);
    if(y != 0)
    rn(y,a);
}

int main(){
    cin >> t;
    fact[0] = 1;
    for(int i = 1; i <= 200002; i++){
        fact[i] = fact[i - 1] * i % Mod;
    }
    while(t--){
        for(int i = 1; i <= n; i++){
            edg[i].clear();
            leaf[i] = false;
            inf[i] = {0,0};
        }
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            cin >> e >> u;
            edg[e].pb(u);
            edg[u].pb(e);
        }
        if(m >= n){
            cout << 0 << endl;
            continue;
        }
        x = 0;
        for(int i = 1; i <= n; i++){
            if(edg[i].size() == 1){
                leaf[i] = true;
            } else x = i;
        }
        if(x == 0){
            cout << 2 << endl;
            continue;
        }
        edg[x].pb(0);
        fg = false;
        ans = 1;
        cot(x,0);
        rn(x,0);
        if(fg == true){
            cout << 0 << endl;
            continue;
        }
        cout << ans * 2 % Mod << endl;
    }
}
