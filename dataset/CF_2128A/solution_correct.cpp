#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1000000007;


auto fill_sieve(int n)
{
    vector < int > s(n + 1, 1); // 1 means prime
    s[0] = 0;
    s[1] = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            s[j] = 0;
        }
    }
    return s;
}

ll gcd(ll a , ll b){
    if(a < b)swap(a,b) ;
    if(b == 0)return a ;
    return gcd(a%b,b) ;
}
void solve()
{
    ll n,c ;
    cin>>n>>c;
    vector<ll> v(n,0) ;
    for(auto &e : v)cin>>e ;
    sort(v.begin(),v.end()) ;
    auto it = upper_bound(v.begin(),v.end(),c) ;
    auto idx = it - v.begin() ;
    idx -- ;
    int cnt = 0 ;
    int num = 0 ;
    while(idx >= 0)
    {
        ll a = v[idx]<<cnt ;
        if(a <= c)
        {
            cnt++ ;
            num++;
        }
        idx-- ;
    }
    ll ans = n - num ;
    cout<<ans<<"\n" ;
    
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>> t ;
    // t = 1 ;
    while (t--) {
        solve();
    }
    return 0;
}