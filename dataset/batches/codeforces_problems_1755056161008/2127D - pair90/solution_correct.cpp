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


int32_t main()
{
    IOS int t;cin >> t;
    factorialinit();
    while(t--){
        int n;cin >> n;
        int m;
        cin >> m;
        graphinit(n, m);
        if(m>n-1){
            cout << 0 << endl;
            continue;
        }
        if(n==1){
            cout << 2 << endl;
            continue;
        }
        //int ans = 1;
        set<int> st;
        for (int i = 1; i <= n;i++){
            if(grp[i].size()==1){
                st.insert(i);
            }
        }
        int ans = 1;
        int nm = 0;
        for (int i = 1;i<=n;i++)
        {
            int ct = 0;
            for(auto itr : grp[i])
            {
                if(grp[itr].size()!=1){ct++;}

            }
            if(ct>2){ans=0;
                break;
            }
            ans = ans *1LL* ff[(grp[i].size() - ct)] % mod;
        }
        if(st.size()+1<n)
        {
            ans = ans * 2 % mod;
        }
        cout << 2 * ans % mod << endl;
    }
    return 0;}
