#include<bits/stdc++.h>
// #include "debug_header.h"
using namespace std;
#define ll long long
#define v vector
#define st string
#define q queue
#define p pair
#define mp map

void solve(){
    int n;
    cin>>n;
    v<int>ds(n+1);
    for(int i=1;i<n+1;i++){
        int x;
        cin>>x;
        ds[i]=x;
    }
    v<ll>cnt(n+1);
    if(ds[2]>ds[1])
        cnt[1]=1;
    for(int i=3;i<n+1;i++){
        if(ds[i]>ds[i-1])
            cnt[i-1]=1;
        if(ds[i]>ds[i-2])
            cnt[i-2]=1;
    }
    for(int i=1;i<n+1;i++){
        if(cnt[i]){
            cnt[i] = i;
        }
        cnt[i]+=cnt[i-1];
    }
    ll ans = 0;
    for(ll i=1;i<n+1;i++){
        ll sub = (i*(i+1))/2;
        sub-=cnt[i-1];
        ans+=sub;
    }
    cout<<ans<<"\n";
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}