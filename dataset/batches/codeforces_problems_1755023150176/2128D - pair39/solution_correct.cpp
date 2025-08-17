#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>


void solve()
{
    ll n; cin >> n;
    ll ans = 0;

    ll mult=1, mines=0;
    for(mines; mines<n; mines++, mult++)
    {
        ans += mult * (n - mines);
    }

//    cout << ans <<  endl;

    vector<int> v(n);
    for(auto &x : v) cin >> x;

    for(int i=0; i<n-1; i++)
    {
        if (v[i] < v[i + 1])
            ans -= (i + 1) * (n - i - 1);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}