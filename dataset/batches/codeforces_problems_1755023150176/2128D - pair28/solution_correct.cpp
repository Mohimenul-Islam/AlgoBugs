#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5000;
void solve() {
	ll n;
    cin >> n;
    ll a[n+1];
    for(ll i=1; i<=n; ++i) cin >> a[i];
    ll ans=0, s=0;
    for(ll i=1; i<=n; ++i){
        s+=i;
        ans+=s;
    }
    ll res=0;
    for(int i=1; i<n; ++i){
        if(a[i]<a[i+1]){
            res+=(i*(n-i));
        }
    }
    cout << ans-res << endl;

}    
int main()
{
	int t;
	t=1;
	cin >> t;
	while(t--){
		solve();
	}
}