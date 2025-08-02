#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        vector<ll> a(n), ans, ans1,ans2, b(n), c(n);
        ll maxi = 0;
        ll mini = 2e6;
        bool l = false , r = false;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
        }
        b = a;
        ll bmin = b[0];
        for(ll i = 0; i < n; i++){
            c[i] = a[n-i-1];
        }
        ll cmax= c[0];
        ans.push_back(1);
        ans1.push_back(1);
        ans2.push_back(1);
        for (ll i = 1; i < n-1; i++){
            if(c[i] >= cmax){
                ans2.push_back(1);
                cmax = c[i];
            }
            else ans2.push_back(0);
        }
        for (ll i = 1; i < n-1; i++){
            if (a[i] <= bmin){
                bmin = a[i];
                ans1.push_back(1);
                }
            else ans1.push_back(0);
        }
        ans1.push_back(1);
        ans2.push_back(1);
        for (ll i = 1; i < n-1; i++){
            if (ans1[i] == 1 || ans2[n-i-1] == 1) ans.push_back(1);
            else ans.push_back(0);
        }
        ans.push_back(1);
        for (auto i : ans){
            cout << i ;
        }
        cout << endl;

    }
}