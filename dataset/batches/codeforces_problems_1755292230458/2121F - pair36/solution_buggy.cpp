#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main () {
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
        unordered_map<int, int> wher;
        for (int i = 0; i<n; i++) {
            if (nums[i] == x) {
                int j = i; 
                wher[pref[j]]++;
                j--;
                while (j >= 0 && nums[j] < x) {
                    wher[pref[j]]++;
                    j--;
                }
                total += wher[pref[i+1]-s];
                continue;
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

