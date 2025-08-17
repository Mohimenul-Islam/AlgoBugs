#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define watch(x) cout<<(#x)<<" = " <<(x)<<endl;
#define test int t; cin>>t; while(t--)
#define gcin(s) getline(cin, s);
#define vi vector<int>
#define pb push_back
#define all(v) v.begin(), v.end()
#define vll vector<long long>
#define vv(name, type, rows, cols) vector<vector<type>> name(rows, vector<type>(cols))
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ge(i) get<i>
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))
const int N=2e5+10;
const int M=1e9+7;
vll fact(N);



void solve(){

    int n, m;
    cin>>n>>m;
    vv(g, int, n+1, 0);
    f(i, 1, m){
        int a, b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    if(n-1!=m){
        cout<<0<<endl;
        return;
    }

    int cnt=0;
    ll ans=1;
    f(i, 1, n){
        if(g[i].size()<=1) continue;
        cnt++;
        ll leaf_cnt=0;
        for(auto &j:g[i]){
            if(g[j].size()==1) leaf_cnt++;
        }
        if(g[i].size()-leaf_cnt>=3){
            cout<<0<<endl;
            return;
        }
        ans=(1LL*ans*fact[leaf_cnt])%M;
    }

    if(cnt<=1) ans=(ans*2)%M;
    else ans=(ans*4)%M;
    cout<<ans<<endl;
}

int main(){
    fastio;
    fact[0]=1;
    f(i, 1, N-1) fact[i]=(fact[i-1]*i)%M;
    test solve();
    return 0;
}