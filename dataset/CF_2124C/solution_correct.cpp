#include <bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define ln node*2
#define rn node*2+1
#define mid (l+r)/2
#define pb push_back
#define pll pair<ll,ll>
#define no void (cout <<"NO" << endl)
#define T ll tt ; cin>>tt ; while(tt--)
#define yes void (cout << "YES" << endl)
#define fast ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
typedef long long ll;
typedef long double ld;
using namespace std ;
const ll oo = 1e18+7 ;
const ll N = 600009 ;
ll n , m , k , l , r , a[N];
ll lcm(ll x , ll y){
    return (x*y)/__gcd(x,y) ;
}
void solve(){
    cin >> n ;

    for(ll i=0 ; i<n ; i++){
        cin >> a[i] ;
    }

    set<ll>st ;

    ll ans=1 ;

    for(ll i=0 ; i<n-1 ; i++){
        if(a[i+1]%a[i]==0)continue ;
        ll g = __gcd(a[i] , a[i+1]) ;
        ll x = a[i]/g ;

        ans = lcm(ans , x) ;
    }
    cout << ans << endl ;
}
int main(){
fast ;
T solve() ;
}
