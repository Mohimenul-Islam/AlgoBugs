#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vc vector<long long>
#define vb vector<bool>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define fo(i, n) for (int i = 0; i < n; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define in insert
#define ff first
#define ss second
#define sz(x) (int)(x.size())
#define endl '\n'
const int mod = 1e9 + 7;
const int inf = 1e9+100;
const int N = 1e6;
vector<int> fact(N);
void solve()
{
    int n,m;cin >> n >> m;
    vector<vi> adj(n + 1);
    fo(i, m)
    {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> color(n + 1, -1);
    function<bool()> isbip = [&]()
    {
        queue<int> q;
        rep(i,1,n+1)
        {
            if(color[i] == -1)
            {
                q.push(i);
                color[i] = 0;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node])
                    {
                        if(color[it] == -1)
                        {
                            color[it] = 1 - color[node];
                            q.push(it);
                        }
                        else if(color[it] == color[node])
                        {
                            return false; 
                        }
                    }
                }
            }
        }
        return true;
    };
    if(!isbip())
    {
        cout << 0 << endl;
        return;
    }
    vector<bool> vis(n+1,0);
    vector<int> temp;
    rep(i,1,n+1)
    {
        int ans = 1;
        if(!vis[i])
        {
            bool nonlf0 = 0;
            bool nonlf1 = 0;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                if(sz(adj[u])>1)
                {
                    if(color[u] == 0)nonlf0 = 1;
                    else nonlf1 = 1;
                }
                int tct = 0;
                for(auto v : adj[u])if(sz(adj[v])==1)tct++;
                for(auto v : adj[u])
                {
                    if(!vis[v])
                    {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
                if(sz(adj[u])-tct > 2)
                {
                    cout << 0 << endl;
                    return;
                }
                ans = (ans*1LL*fact[tct]) % mod;
            }
            if(nonlf1 && nonlf0)ans=(ans*2LL) % mod;
            temp.pb(ans);
        }
    }
    int res = fact[sz(temp)];
    for(auto x : temp)res = (res * 1LL * x) % mod;
    cout << (res*2LL)%mod << endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    rep(i, 1, N)fact[i] = (fact[i - 1] *1ll* i) % mod;
    int t = 1;cin >> t;
    while(t--)solve();
    return 0;
}


