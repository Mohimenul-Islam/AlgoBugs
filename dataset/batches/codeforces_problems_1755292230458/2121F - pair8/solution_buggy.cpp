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
        in n >> s >> x;
        vector<int> a(n);
        loop(n) {
            in a[i];
        }

        vector<int> pref(n+1, 0);
        loop(n) {
            pref[i+1] = pref[i] + a[i];
        }

        vector<int> nge(n, n);
        stack<int> st;
        for (int i = n-1; i>=0;i--) {
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            if (!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop(); 

        vector<int> pge(n, -1);
        loop(n) {
            while (!st.empty() && a[st.top()]<a[i]) st.pop();
            if (!st.empty()) pge[i] = st.top();
            st.push(i);
        }

        int cnt = 0;
        loop(n) {
            if (a[i] != x) {
                continue;
            }

            int lb = pge[i] + 1;
            int rb = nge[i];

            if (i-lb< rb-1-i) {
                map<int, int> freq;
                for (int r = i; r < rb; r++) {
                    freq[pref[r + 1]]++;
                }
                for (int l = lb; l <= i; l++) {
                    int x = s + pref[l];
                    if (freq.count(x)) {
                        cnt += freq[x];
                    }
                }
            } else {
                map<int, int> freq;
                for (int l=lb; l<=i; l++) {
                    freq[pref[l]]++;
                }
                for (int r = i; r < rb; r++) {
                    int x = pref[r + 1] - s;
                    if (freq.count(x)) {
                        cnt += freq[x];
                    }
                }
            }
        }

        out cnt << endl;

    }

    return 0;
}
