//Written By Aryan Sanghi

// #include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<stack>
#include<map>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n;i++)
#define repi(i, a, n) for(ll i = a;i < n;i++)
#define repii(i, a, n, b) for(ll i = a;i < n;i += b)
#define pb push_back
#define fst first
#define snd second

const ll mod=1000000007;

vector<vector<ll> > v;
vector<ll> vis;

ll modpower(ll a, ll b, ll c)
{
    ll r=1;
    
    a=a%c;
    
    while(b>0)
    {
        if(b%2==1)
        r=(r*a)%c;
        
        b=b/2;
        a=(a*a)%c;
        
    }
    
    return r;
}

ll mini(ll a, ll b){
    if(a<b) return a;
    return b;
}

ll maxi(ll a, ll b){
    if(a>b) return a;
    return b;
}

ll gcd(ll a, ll b)
{
    if(b == 0)
    return a;
    
    if(a == 0)
    return b;
    
    if(a > b)
    return gcd(b, a % b);
    
    return gcd(a, b % a);
}

void solve(){
    ll n, s, x;
    cin>>n>>s>>x;

    ll a[n];
    rep(i, n) cin>>a[i];

    ll r=0, csum=0, ans=0, fd=0;

    map<ll, ll> mp1, mp2;

    for(r=0;r<n;r++){
        if(a[r]==x){
            fd=1;
            for(auto& it:mp2) mp1[it.fst]+=it.snd;
            mp2.clear();
        }
        if(a[r]>x){
            mp1.clear();
            mp2.clear();
            csum=0;
            fd=0;
        }
        else{
            csum+=a[r];
            if(csum==s & fd) ans++;
            if(mp1.find(csum-s) != mp1.end()) ans += mp1[csum - s];
            mp2[csum]++;
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin>>t;

    while(t--)
    {
        solve();
    }
}
