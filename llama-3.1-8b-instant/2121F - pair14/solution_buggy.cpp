#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define se second
#define pb push_back
#define fi first
#define fo(var, n) for(long long var=0;var<n;var++)
#define fore(var, n) for(long long var=n-1;var>=0;var--)
using namespace std;
using ll = long long;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin>>tt;

    while(tt--)
    {
        ll n,s,x;cin>>n>>s>>x;
        ll a[n];
        fo(i, n) cin>>a[i];
        ll pref[n+1]; pref[0]=0;
        fo(i,n) pref[i+1]=pref[i]+a[i];
        map<ll,int> b;
        fo(i,n+1) if(i != 0 && a[i-1] > x) break; else b[pref[i]]++;
        ll ans = 0;
        fo(i, n)
        {
            if(a[i] > x)
            {
                b.clear();
                for(int j = i+1; j < n+1; j++) if(j > i && j < n && a[j] > x) break; else b[pref[j]]++;
               // for(auto x:b) cout<<x.fi<<" "<<x.se<<"\n";
                continue;
            }
            b[pref[i]]--;
            if(a[i] < x) continue;

            int j = i-1;
            while(j >= 0 && (a[j] < x || j == i))  j--;
            j++;
            while(j<=i) {ans += b[pref[j] + s]; j++;}
        }
        cout << ans << "\n";
  // skul wa inc skul
    }

    return 0;
}
