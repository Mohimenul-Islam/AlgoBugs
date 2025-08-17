#include <bits/stdc++.h>
using namespace std;
#define ll int

void solve(){
    ll n;
    cin >> n;
    ll total = 0;
    for (ll i = 0; i <= n; i++) total+=i*(n-i+1);
    vector<ll> a(n);
    for (ll i =0;i < n; i++){
        cin >> a[i];
        if (!i) continue;
        if (a[i]>a[i-1]){
            total-=(i*(n-i));
        }
    }
    cout << total<<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin>>t;
    while (t--) solve();
}