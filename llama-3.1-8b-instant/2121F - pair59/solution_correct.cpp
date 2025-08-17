#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define fr(n) for(int i = 0; i < n; i++)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, s, x;
        cin >> n >> s >> x;
        vi a(n);
        fr(n) cin >> a[i];
        vi b(n, n), c(n, n), p(n, a[0]);
        fr(n){
            ll j = n-1 - i;
            if (a[j] == x){
                b[j] = j;
            }
            else {
                if (j == n-1){
                    b[j] = n;
                }
                else {
                    b[j] = b[j+1];
                }
            }
            if (a[j] > x){
                c[j] = j;
            }
            else {
                if (j == n-1){
                    c[j] = n;
                }
                else {
                    c[j] = c[j+1];
                }
            }
            if (i < n-1)
                p[i+1] = p[i] + a[i+1];
        }
        map<ll, vector<ll>> mp;
        fr(n){
            if (mp.find(p[i]) == mp.end()) {
                mp[p[i]] = vector<ll>();
            }
            mp[p[i]].push_back(i);
        }
        ll ans = 0;
        fr(n){
            if (b[i] >= c[i]) {
                continue;
            }
            ll des = s;
            if (i > 0) {
                des += p[i-1];
            }
            if (mp.find(des) == mp.end()) {
                continue;
            }
            auto& vec = mp[des];
            auto it1 = lower_bound(vec.begin(), vec.end(), b[i]);
            auto it2 = lower_bound(vec.begin(), vec.end(), c[i]);
            ans += it2-it1;
        }
        cout << ans << endl;
    }
}