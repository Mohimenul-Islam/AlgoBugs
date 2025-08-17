#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; 
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
#define vvii vector<vector<pair<int, int>>>
#define inp2(a, n) {a.clear(); a.resize(n); for(auto &i : a) cin>>i;}
#define print(a) {for(auto i : a) cout<<i<<" "; cout << endl;}
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define F first
#define S second
const int N = 2e5+10;
const int M = 1e9+7;

int inv(int i) {if (i == 1) return 1; return (M - ((M / i) * inv(M % i)) % M) % M;}
int mod_mul(int a, int b) {a = a % M; b = b % M; return (((a * b) % M) + M) % M;}

int n, s, x;
vi a;
map<int, vi> cnt;

void solve(){
    cin>>n>>s>>x;
    inp2(a, n);
    cnt.clear();
    cnt[0].pb(-1);
    int idx=-1, sum=0, ans=0;
    for(int i=0; i<n; i++){
        if(a[i]>x) {sum=0; cnt.clear(); cnt[0].pb(i); continue;}
        if(a[i]==x) idx=i;
        sum+=a[i];
        if(cnt[sum-s].size()){
            int x=lower_bound(all(cnt[sum-s]), idx)-cnt[sum-s].begin();
            ans+=x;
        }
        cnt[sum].pb(i);
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin>>t;
    while (t--) solve();

return 0;
}