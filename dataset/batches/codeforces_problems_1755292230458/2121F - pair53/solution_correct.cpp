#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);
ll const maxn = 2e5 + 5;


int main()
{
    fast
    ll t;
    cin>>t;
    while(t--){
        ll n,x,s; cin>>n>>s>>x; ll a[n]; ll pref[n];
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        ll ans = 0;
        map<ll, ll> mp;
        ll prev = 1;
        for (ll r = 1; r <= n; r++) {
            if (a[r] > x) {mp.clear(); prev = r + 1;}
            else if (a[r] == x) {
                while (prev <= r) {
                    mp[pref[prev - 1]]++;
                    prev++;
                }
            }
            ans += mp[pref[r] - s];
        }
        cout<<ans<<endl;

    }
}