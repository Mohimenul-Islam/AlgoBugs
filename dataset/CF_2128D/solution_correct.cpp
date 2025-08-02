#include <bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define nl "\n"
#define pb push_back
#define pk pop_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define fo(i,a,b) for(auto i=a;i<b;i++)
#define fob(i,a,b) for(auto i=a;i>=b;i--)
#define sortall(x) sort(all(x))
#define inf 1e18
#define yes cout<<"YES"<<nl
#define no  cout<<"NO"<<nl
#define sum(arr) accumulate(all(arr),0ll)

using ll  = long long;
using lld = long double;
using pi  = pair<int,int>;
using pl  = pair<ll,ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define maxHeap(t) priority_queue<t>
#define minHeap(t) priority_queue<t,vector<t>,greater<t>>

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

/* ---------------- overloads ---------------- */
template<class T>
istream& operator>>(istream& in, vector<T>& v){ for(T& x: v) in>>x; return in; }
template<class T>
ostream& operator<<(ostream& out, const vector<T>& v){ for(const T& x: v) out<<x<<" "; return out; }

/* ---------------- utils ---------------- */
template<class... T> void read(T&... args){ (cin>>...>>args); }
template<class T>    bool even(T x){ return !(x&1); }
int  popcnt (int x){ return __builtin_popcount (x); }
int  popcnt (ll  x){ return __builtin_popcountll(x); }
int  parity (int x){ return __builtin_parity (x); }
int  parity (ll  x){ return __builtin_parityll(x); }
int  topbit (int x){ return x? 31-__builtin_clz (x):-1; }
int  topbit (ll  x){ return x? 63-__builtin_clzll(x):-1; }
int  lowbit (int x){ return x? __builtin_ctz (x):-1; }
int  lowbit (ll  x){ return x? __builtin_ctzll(x):-1; }

const int mod=1e9+7;
ll modpow(ll a,ll b,ll m){a%=m;ll r=1%m;while(b){if(b&1) r=1LL*r*a%m;a=1LL*a*a%m;b>>=1;}return r;}
ll inv(ll a,ll m){return modpow(a,m-2,m);}
vl fact(int n){vl f(n+1);f[0]=1;fo(i,1,n+1) f[i]=f[i-1]*i%mod;return f;}
vl invfact(int n,const vl& f){vl g(n+1);g[n]=inv(f[n],mod);fob(i,n,1) g[i-1]=g[i]*i%mod;return g;}
ll nCr(int n,int r,const vl& f,const vl& g){return (r<0||r>n)?0:f[n]*g[r]%mod*g[n-r]%mod;}

int upperBound(const vi& a,int l,int r,int x){ int id=a.size();while(l<=r){int m=l+(r-l)/2; if(a[m]>=x){id=m;r=m-1;} else l=m+1;}return id;}
int lowerBound(const vi& a,int l,int r,int x){int id=-1;while(l<=r){ int m=l+(r-l)/2; if(a[m]<=x){ id=m;l=m+1;} else r=m-1;}return id;}

bool checkComp(ll n,ll a,ll d,int s){ ll x=modpow(a,d,n); if(x==1||x==n-1) return false; fo(i,1,s){ x=1LL*x*x%n; if(x==n-1) return false; } return true; }
bool isPrime(ll n){ if(n<2) return false; int s=0; ll d=n-1; while(!(d&1)){ d>>=1; ++s; } for(int a:{2,3,5,7,11,13,17,19,23,29,31,37}){ if(a==n) return true; if(checkComp(n,a,d,s)) return false; } return true; }
vl sieve(ll n){ vector<char> isp(n+1,true); for(ll p=2;p*p<=n;++p) if(isp[p]) for(ll i=p*p;i<=n;i+=p) isp[i]=false; vl v; for(ll i=2;i<=n;++i) if(isp[i]) v.pb(i); return v; }

vpl factorize(ll n){ vpl f; for(ll p=2;p*p<=n;++p) if(n%p==0){ int c=0; while(n%p==0){ n/=p; ++c; } f.pb({p,c}); } if(n>1) f.pb({n,1}); return f; }
vl divisors(ll n){ auto fac=factorize(n); vl d{1}; for(auto [p,e]:fac){ int sz=d.size(); ll cur=1; fo(i,1,e+1){ cur*=p; fo(j,0,sz) d.pb(d[j]*cur); } } sortall(d); return d; }

/* ------------------------------------------------------------------- */

void solve(int tc){

    ll n;read(n);
    vl p(n);read(p);

    ll ans=(n*(n+1)*(n+2))/6;
    fo(i,0,n-1){
        if(p[i]<p[i+1]){
            ans-=(i+1)*(n-i-1);
        }
    }
    cout<<ans<<nl;

}

int main(){
    fastio();
    int t; read(t);
    int tc = t;
    while(t--){
        solve(tc - t);
    }
    return 0;
}
