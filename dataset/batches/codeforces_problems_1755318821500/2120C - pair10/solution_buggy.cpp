#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define invl(v) for(auto &x: v) cin >> x;
#define all(v) (v).begin(), (v).end()
#define f(p,q,n) for(ll p = q; p < n; p++)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vi vector<ll>

const ll mod = 1e9 + 7;
const ll INF = LLONG_MAX >> 1;

void solve(ll tt = 0){
    ll n,k; cin >> n >> k;
    if(k < n || k > (n*(n+1))/2){
        cout << "-1\n";
        return;
    }
    vi arr(n);
    f(i,0,n) arr[i] = n-i;

    f(i,0,n){
        ll val = k -(n-i); 
        if(k == n-i){
            swap(arr[i],arr[n-1]);
            break;
        }
        else if(val < arr[i]){
            k = n-i-1;
            swap(arr[i],arr[k-val]);
        }
        else{
            k-= arr[i];
        }
    }

    cout << arr[0] << '\n';
    f(i,1,n){
        cout << arr[i-1] << " " << arr[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    for(ll i = 1; i <= t; i++)
        solve();
}