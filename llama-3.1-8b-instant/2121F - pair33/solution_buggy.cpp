#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, s,x;
        cin >> n >> s>>x;
        vector<ll> a(n+1),pref(n+1);
        for(ll i=1;i<=n;i++){
          cin>>a[i];
          pref[i]=pref[i-1]+a[i];
        }
        unordered_map<ll,ll> d;
        ll lef=1,cnt=0;
        for(ll i=1;i<=n;i++){
          if(a[i]>x) {
            d.clear(); lef=i+1;
          }
          else if(a[i]==x){
            while(lef<=i){
              d[pref[lef-1]]++;
              lef++;
            }
          }
          cnt+=d[pref[i]-s];
        }
        
        cout<<cnt<<endl;
    }

    return 0;
}
