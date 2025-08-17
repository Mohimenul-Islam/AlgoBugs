#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<pair<ll,ll>> vp;

#define all(v) v.begin(), v.end()
#define vecMAX(a) *max_element(all(a))
#define vecMIN(a) *min_element(all(a))
#define srt(v) sort(all(v))
#define rev(v) reverse(all(v))
#define pb push_back

const int mod7 = 1000000007;
const ll inf = 1e18;
const int mod9 = 998244353;


void solve(){
    
    ll n, s, x;
    cin >> n >> s >> x;

    vector<ll> arr(n);
    vector<ll> p(n+1,0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        p[i+1] = p[i] + arr[i];
    }

    map<ll, int> mp;

    mp[0] = 1;

    ll cs = 0;
    ll ans = 0;
    ll cl = -1, cn = -1;
    bool f = 0;

    for(ll i = 0; i < n; i++) {

        if(arr[i] > x)
        {
            mp.clear();
            f = 0;
            cs += arr[i];
            mp[cs] = 1;
            cn = i;
            continue;
        }

        if(arr[i] == x) {
            if(!f)
            {
                cl = i;
                f = 1;
            }
            else
            {
                for(ll j = cl; j < i; j++) {
                    mp[p[j+1]]++;
                }
                cl = i;
            }
        }

        cs += arr[i];
        if(f) ans += mp[cs - s];

        if(!f) mp[cs]++;
        
    }

    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}