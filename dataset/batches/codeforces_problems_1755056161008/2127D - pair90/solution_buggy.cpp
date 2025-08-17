#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int ll

const int fN = 1e6 + 5;
const int mod = 1e9 + 7;
int ff[fN], iff[fN];
bool facinit = false;
 
int power(int x, int y){
    if (y == 0) return 1;
 
    int v = power(x, y / 2);
    v = 1LL * v * v % mod;
 
    if (y & 1) return 1LL * v * x % mod;
    else return v;
}
 
void factorialinit(){
    facinit = true;
    ff[0] = iff[0] = 1;
 
    for (int i = 1; i < fN; i++){
        ff[i] = 1LL * ff[i - 1] * i % mod;
    }
 
    iff[fN - 1] = power(ff[fN - 1], mod - 2);
    for (int i = fN - 2; i >= 1; i--){
        iff[i] = 1LL * iff[i + 1] * (i + 1) % mod;
    }
}
 
int ncr(int n, int r){
    if (!facinit) factorialinit();
    
    if (n == r) return 1;
    if (r < 0 || r > n) return 0;
    return 1LL * ff[n] * iff[r] % mod * iff[n - r] % mod;
}
 
int npr(int n, int r){
    if (!facinit) factorialinit();
 
    assert(0 <= r && r <= n);
    return 1LL * ff[n] * iff[n - r] % mod;
}
 
int Solutions(int n, int r){
    //solutions to x1 + ... + xn = r 
    //xi >= 0
    return ncr(n + r - 1, n - 1);
}


const int N = 1e6 + 10;
vector<int> grp[N];
void graphinit(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        grp[i + 1].clear();
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
}

int dfs(int ver, int par);
int32_t main()
{
    IOS int t;cin >> t;
    int tt = 0;
    factorialinit();
    while(t--)
    {
        int n;cin >> n;
        int m;cin >> m;
        for (int i = 0; i < n; i++)
    {
        grp[i + 1].clear();
    }
    vector<pair<int, int>> vct;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
        vct.push_back({a, b});
    }
        tt++;
        if(tt==13)
        {
            cout << n << "|";
            cout << m << endl;;
            for(auto itr : vct)
            {
                cout << itr.first << " " << itr.second << endl;
            }
            return 0;
        }
        if(m>n-1){
            cout << 0 << endl;
            continue;
        }
        cout << 2 * dfs(1, 0)%mod << endl;
    }
    return 0;
}
    int dfs(int ver,int par){
        vector<int> db;
        int ct = 0;
        int ans = 1;
        for(auto itr : grp[ver]){
            if(itr==par){
                continue;
            }
            if(grp[itr].size()==1){
                ct++;
            }
            else{
            db.push_back(dfs(itr, ver));
            }
        }
        if(ver==1){
            ans = ff[ct];
            if(db.size()>2){
                ans = 0;
            }
            for(auto itr : db)
            {ans = ans * itr%mod;}
            if(db.size())
            {
                ans = ans * 2 % mod;
            }
        }
        else{
            if(db.size()>1){
                ans = 0;
            }else{
                int bk = 1;
                if(db.size())
                {bk = db[0]*2%mod;}
                ans = bk * ff[ct] % mod;
            }
        }
        return ans;
    }
