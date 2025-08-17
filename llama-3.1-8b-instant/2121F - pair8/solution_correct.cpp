#include <bits/stdc++.h>
using namespace std;
#define loop(n) for (int i = 0; i < n; i++)
#define fr(i,m,n) for(int i = m; i < n; i++)
#define in cin>>
#define out cout<<
#define pb push_back
#define pp pop_back()
#define int long long int
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl

signed main(){
    int t;
    in t;
    while (t--) {
        int n;
        int s, x;
        in n>>s>>x;
        vector<int> a(n);
        loop(n) {
            in a[i];
        }

        vector<int> pref(n+1, 0);
        loop(n) {
            pref[i + 1] = pref[i] + a[i];
        }

        auto lamb = [&](int maxi) {
            int ans = 0;
            map<int, int> m;
            int lef = 0;
            m[pref[lef]] = 1;

            fr(i,1,n+1) {
                if (a[i-1]>maxi) {
                    m.clear();
                    lef = i;
                    if (lef <= n) {
                        m[pref[lef]] = 1;
                    }
                    continue;
                }
                
                int rem = pref[i] - s;
                if (m.count(rem)) {
                    ans += m[rem];
                }
                m[pref[i]]++;
            }
            return ans;
        };

        int fi = lamb(x);
        int fo = lamb(x - 1);

        out  fi - fo<<endl;
    }

    return 0;
}