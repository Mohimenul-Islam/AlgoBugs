#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
#define indexed_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long
#define nl endl

struct range{
    int start, end , index;
    bool operator<(auto &other){
        if(start == other.start) return end < other.end;
        return start < other.start;
    }
};

void solve(){
    int n; cin >> n;
    vector <pair <int , int> > v(2*n+1, {0, -1});
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(v[a].first < b){
            v[a].first = b;
            v[a].second = i;
        }
    }
    set  <int> ans;
    for(auto &x : v) if(x.second != -1) ans.insert(x.second);
    cout << ans.size() << nl;
    for(auto &x : ans) cout << x+1 << ' ';
        cout << nl;
} 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    // freopen("error.txt", "w", stderr);
    // freopen("roboherd.in", "r", stdin);
    // freopen("roboherd.out", "w", stdout);
    int te; cin >> te;
    while (te--)
        solve();
}