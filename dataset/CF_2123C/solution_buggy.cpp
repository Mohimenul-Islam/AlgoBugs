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
        c = a;
        ans.push_back(1);
        for (ll i = 1; i < n-1; i++){
            if (a[i] == mini || a[i] == maxi){
                ans2.push_back(1);
                continue;
            }
            sort(c.begin() + i , c.end());
            if(c[n-1]== a[i]) ans2.push_back(1);
            else ans2.push_back(0);
        }
        for (ll i = 1; i < n-1; i++){
            if (a[i] == mini || a[i] == maxi){
                ans1.push_back(1);
                continue;
            }
            sort(b.begin(), b.begin() + i + 1);
            if(b[0]== a[i]) ans1.push_back(1);
            else ans1.push_back(0);
        }
        for (ll i = 0; i < n-2; i++){
            if (ans1[i] == 1 || ans2[i] == 1) ans.push_back(1);
            else ans.push_back(0);
        }
        ans.push_back(1);
        for (auto i : ans){
            cout << i ;
        }
        cout << endl;

    }
}