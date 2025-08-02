#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n ;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int start = 0;
    while (mp.count(start)) start++;
    vector<int> ans(n+2);

    for (int j = start; j >= 0; j--) {
        int L = mp[j];     
        int R = n - j;     
        if (L <= R) {
            ans[L]++;     
            ans[R + 1]--;  
        }
    }
    int y = 0;
    for(auto &i:ans){
        y+=i;
        i = y;
    }
    for (int i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}