#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, s, x;
vector<int> a;
vector<pair<int,int>> sg;

void build(int nd, int l, int r){
    if (l == r) {
        sg[nd] = {a[l], a[l]};
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*nd, l, mid);
    build(2*nd+1, mid+1, r);

    sg[nd].first  = sg[2*nd].first  + sg[2*nd+1].first;
    sg[nd].second = max(sg[2*nd].second, sg[2*nd+1].second);
}

pair<int,int> query(int nd, int tl, int tr, int l, int r){
    if (l > tr || r < tl || l > r){
        return {0, numeric_limits<int>::min()};
    }
    if (l <= tl && r >= tr) return sg[nd];

    int mid = tl + (tr - tl) / 2;
    auto left  = query(2*nd, tl, mid, l, r);
    auto right = query(2*nd+1, mid+1, tr, l, r);

    int sum = left.first + right.first;
    int mx  = max(left.second, right.second);
    return {sum, mx};
}

void solve(){
    cin >> n >> s >> x;
    a.resize(n);
    sg.assign(4*n, {0, numeric_limits<int>::min()});

    for (int i = 0; i < n; ++i) cin >> a[i];

    build(1, 0, n-1);

    map<int, vector<int>> mp;
    // mp.resize(n * 2);
    mp[0].push_back(-1);

    int pref = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        pref += a[i];
        int ss = pref - s;
        auto it = mp.find(ss);
        if (it != mp.end()){
            for (int j : it->second) {
                int str = j + 1;
                auto res = query(1, 0, n-1, str, i);
                if (res.second == x) cnt++;
            }
        }
        mp[pref].push_back(i);
    }

    cout << cnt << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
