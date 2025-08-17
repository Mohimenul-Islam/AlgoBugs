#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vpll vector<pair<long long, long long>>
#define pll pair<long long, long long>
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(),v.end())
#define vsortd(v) sort(v.begin(),v.end(),greater<int>())
#define forl(i,k,n) for(ll i=k; i<n; i++)
#define rforl(i,k,n) for(ll i=k; i>n; i--)
#define inp(a,n) for(ll i=0; i<n; i++) cin>>a[i]
#define maxpq priority_queue<ll>
#define minpq priority_queue<ll,vector<ll>,greater<ll>>
#define pv(v) for(auto x:v) {cout<<x<<" ";} cout<<endl;
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pyr cout<<"YES"<<endl;return
#define pnr cout<<"NO"<<endl;return
#define p(x) cout<<x<<endl
#define mod 1000000007

vll presum(vll a, ll n){
    forl(i,1,n) a[i]+=a[i-1];
    return a;
}

vll sufsum(vll a, ll n){
    rforl(i,n-2,-1) a[i]+=a[i+1];
    return a;
}

ll poww(ll a, ll b){
    if(b==0) return 1;
    else if(b%2==0) return poww(a*a, b/2);
    else return a*poww(a*a, b/2);
}

ll find_mex(vll a){
    ll mex=0; set<ll> s;
    forl(i,0,a.size()) s.insert(a[i]);
    for(auto x:s){
        if(x!=mex) break;
        mex++;
    }
    return mex;
}

vll divisors(ll n){
    vll res;
    ll sq=sqrt(n);
    forl(i,1,sq+1){
        if(n%i==0){
            res.push_back(i);
            if(i*i!=n) res.push_back(n/i);
        }
    }
    vsort(res);
    return res;
}

vll sieve(ll n){
    vll isprime(n+1,1);
    forl(i,2,n+1){
        if(isprime[i]){
            for(ll j=i*i; j<=n; j+=i) isprime[j]=0;
        }
    }
    return isprime;
}

void solve()
{
    ll n,m;
    cin>>n>>m;

    if(m<n){
        p(-1);
        return;
    }

    forl(i,1,n+1){
        ll l = ((i)*(i-1))/2;
        ll r = i*(n-i+1);
        if(l+r==m){
            p(i);
            forl(j,1,n){
                cout<<j<<" "<<j+1<<endl;
            }
            return;
        }
        if(l+r>m){
            p(i);
            ll d = l+r-m;
            ll j=n-d+1;
            while(j<n){
                cout<<j<<" "<<j+1<<endl;
                j++;
            }
            cout<<j<<" 1"<<endl;
            j=1;
            while(j<n-d){
                cout<<j<<" "<<j+1<<endl;
                j++;
            }
            return;
        }
    }

    p(-1);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--) solve();
    return 0;
}