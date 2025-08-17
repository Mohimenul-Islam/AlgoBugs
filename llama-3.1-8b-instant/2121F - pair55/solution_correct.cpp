#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count_subarrays(const vector<ll>& seg, ll s) {
    int m = seg.size();
    vector<ll> P(m+1, 0);
    for(int i = 0; i < m; i++)
        P[i+1] = P[i] + seg[i];

    vector<ll> vals;
    vals.reserve((m+1)*2);
    for(int i = 0; i <= m; i++) {
        vals.push_back(P[i]);
        vals.push_back(P[i] - s);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int M = vals.size();
    vector<int> cnt(M, 0);
    auto get_id = [&](ll x){
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };

    ll ans = 0;
    cnt[get_id(P[0])]++;

    for(int j = 1; j <= m; j++) {
        int id_need = get_id(P[j] - s);
        ans += cnt[id_need];
        cnt[get_id(P[j])]++;
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
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll answer = 0;
        int i = 0;
        while(i < n) {
            if(a[i] > x) {
                i++;
                continue;
            }
            int j = i;
            while(j < n && a[j] <= x) j++;
            int m = j - i;
            vector<ll> seg(m);
            for(int k = 0; k < m; k++)
                seg[k] = a[i + k];

            ll tot = count_subarrays(seg, s);

            ll sub = 0;
            int l = 0;
            while(l < m) {
                if(seg[l] == x) {
                    l++;
                    continue;
                }
                int r = l;
                while(r < m && seg[r] < x) r++;
                vector<ll> small_seg(r - l);
                for(int k = l; k < r; k++)
                    small_seg[k - l] = seg[k];
                sub += count_subarrays(small_seg, s);
                l = r;
            }

            answer += tot - sub;
            i = j; 
        }

        cout << answer << "\n";
    }
    return 0;
}
