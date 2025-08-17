#include <bits/stdc++.h>

using namespace std;

#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#define tc int t; cin>>t; while(t--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
typedef long double ld;

const int MAX = 2e5+5;
const int INF = 1e9+5;
const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;

map<ll,ll> mapka;
ll a[MAX], pref[MAX];


void solve()
{
    mapka.clear();
    ll n,s,x,ans=0;
    cin>>n>>s>>x;

    for(int i=1; i<=n; i++) {cin>>a[i]; pref[i]=pref[i-1]+a[i];}
    int l=0;
    for(int r=1; r<=n; r++)
    {
        if(a[r]>x) {mapka.clear(); l=r;}
        if(a[r]==x)
        {
            for(int i=l; i<r; i++) mapka[pref[i]]++;
            l=r;
        }
        //cout<<r<<":"<<secik.count(pref[r]-s)<<"\n";
        ans+=mapka[pref[r]-s];
    }
    cout<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    tc
    solve();

    return 0;
}
