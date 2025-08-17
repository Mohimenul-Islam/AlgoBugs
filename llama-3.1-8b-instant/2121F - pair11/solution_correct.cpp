// bits/stdc++.h substitute
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <bitset>
#include <deque>
#include <list>
#include <tuple>
#include <cstring>
#include <limits>
#include <sstream>
#include <iomanip>
using namespace std;
using ll = long long;

vector<ll> arr;
ll n, x;
ll s;

ll count(ll l, ll r){
    if (l > r) return 0;
    if (l == r){
        if (arr[l] == s) return 1;
        else return 0;
    }
    map<long long, ll> prefixCount;
    prefixCount[0] = 1;  // empty prefix
    long long sum = 0;
    ll ans = 0;

    for (ll i = l; i <= r; i++) {
        sum += arr[i];
        if (prefixCount.count(sum - s)) {
            ans += prefixCount[sum - s];
        }
        prefixCount[sum]++;
    }

    return ans;
}

void solve(){
    cin >> n >> s >> x;
    arr.resize(n);
    for (ll &a : arr) cin >> a;
    ll ans = 0;
    vector<ll> bads, badss;
    for (ll i = 0; i < n; ++i){
        if (arr[i] > x){
            bads.push_back(i);
            badss.push_back(i);
        }
        else if (arr[i] >= x){
            badss.push_back(i);
        }
    }
    if (bads.size() == 0){
        ans += count(0, n-1);
    }
    else{
        ans += count(0, bads[0]-1);
        for (ll i = 0; i < bads.size() - 1; i++){
            ans += count(bads[i]+1, bads[i+1]-1);
        }
        ans += count(bads.back()+1, n-1);
    }
    if (badss.size() == 0){
        ans -= count(0, n-1);
    }
    else{
        ans -= count(0, badss[0]-1);
        for (ll i = 0; i < badss.size() - 1; i++){
            ans -= count(badss[i]+1, badss[i+1]-1);
        }
        ans -= count(badss.back()+1, n-1);
    }
    cout << ans << "\n";
    
    
     
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}