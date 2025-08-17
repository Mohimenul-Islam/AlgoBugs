#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countSum(const vector<ll>& P, ll s){
    unordered_map<ll,int> cnt;
    cnt.reserve(P.size()*2);
    cnt[0] = 1;
    ll ans = 0;
    for(int i=1;i<(int)P.size();i++){
        ans += cnt[P[i] - s];
        cnt[P[i]]++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        ll s, x;
        cin >> n >> s >> x;
        vector<ll>a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        ll answer = 0;
        int i = 0;
        while(i < n){
            if(a[i] > x){
                i++;
                continue;
            }
            int j = i;
            while(j < n && a[j] <= x) j++;
            int m = j - i;
            vector<ll>P(m+1,0);
            for(int k=0;k<m;k++){
                P[k+1] = P[k] + a[i+k];
            }
            ll tot = countSum(P, s);
            ll sub = 0;
            int l = i;
            while(l < j){
                if(a[l] == x){
                    l++;
                    continue;
                }
                int r = l;
                while(r < j && a[r] < x) r++;
                int len = r - l;
                vector<ll>Q(len+1,0);
                for(int k=0;k<len;k++){
                    Q[k+1] = Q[k] + a[l+k];
                }
                sub += countSum(Q, s);
                l = r;
            }
            answer += tot - sub;
            i = j;
        }
        cout << answer << "\n";
    }
    return 0;
}
