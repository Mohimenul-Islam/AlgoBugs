#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main () {    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, s, x; 
        cin >> n >> s >> x;
        vector<int> nums(n);
        vector<int> pref(n+1);
        pref[0] = 0;
        for (int i=0; i<n; i++) {
            cin >> nums[i];
            pref[i+1] = pref[i]+nums[i];
        }


        int total = 0;
        map<int, int> wher;
        for (int i = 0; i<n; i++) {
            if (nums[i] == x) {
                int j = i; 
                wher[pref[j]]++;
                j--;
                while (j >= 0 && nums[j] < x) {
                    wher[pref[j]]++;
                    j--;
                }
            }  
            if (nums[i] > x) {
                wher.clear();
                continue;
            }
            total += wher[pref[i+1]-s];
        }

        cout << total << '\n';
    }
    return 0;
}

