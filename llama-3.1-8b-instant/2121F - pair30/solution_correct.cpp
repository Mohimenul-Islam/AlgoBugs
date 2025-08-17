#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
void solve(){
    int n, s, x, cur = 0, ans = 0;
    cin >> n >> s >> x;
    map<int, vector<int>> mp;
    int mx = -1;
    mp[0].push_back(0);
    int arr[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(arr[i] > x){
            mx =  0;
            cur = 0;
            mp.clear();
            mp[cur].push_back(i);
            continue;
        }
        if(arr[i] == x){
            mx = i;
        }
        cur += arr[i];

        if(mp.count(cur - s)){
            int sz = mp[cur - s].size();
            int l = 0, r = sz - 1, pos = -1;

            while(l <= r){
                int m = l + (r - l) / 2;
                if(mp[cur - s][m] < mx){
                    // if(mp[cur - s][m] != -1 && cur - s != 0) pos = m;
                    pos = m;
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
            // if()
            // cout << pos + 1 << " " << i << endl;
            // if(pos == 0 && cur - s == 0) continue;
            ans += pos + 1;
        }
        mp[cur].push_back(i);
        

    }

    // for(auto [ad, da]: mp){
    //     cout << ad << " : ";
    //     for(auto oo: mp[ad]) cout << oo << " "; cout << endl;
    // }
    cout << ans << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}