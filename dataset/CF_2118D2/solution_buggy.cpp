#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define inf 0x3f3f3f3f
#define all(a) (a).begin(), (a).end()
#define pb emplace_back
// my king
#define int long long

const int MOD = 998244353;

// g++ -o D cfD.cpp -Wall -Wextra -Werror
// D < input.txt

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    for(int i = 0; i < n; i++){
        cin >> p[i + 1];
    }
    vector<int> d(n + 1);
    for(int i = 0; i < n; i++){
        cin >> d[i + 1];
    }
    vector<vector<pair<int, int>>> gor(k);
    vector<vector<pair<int, int>>> gol(k);
    for(int i = 1; i <= n; i++){
        gor[(p[i] - d[i] + k) % k].pb(p[i], d[i]);
        gol[(p[i] + d[i]) % k].pb(p[i], d[i]);
    }
    int q;
    cin >> q;
    auto Go = [&](int curp, int curd, int dir) -> pair<int, int> {
        if(dir){
            auto& clss = gor[(curp - curd + k) % k];
            int nxtidx = upper_bound(clss.begin()
            , clss.end(), make_pair(curp, LLONG_MAX)) - clss.begin();
            if(nxtidx == (int)clss.size()){
                return {-1, -1};
            }
            return clss[nxtidx];
        } else {
            auto& clss = gol[(curp + curd) % k];
            int nxtidx = lower_bound(clss.begin()
            , clss.end(), make_pair(curp, LLONG_MIN)) - clss.begin() - 1;
            if(nxtidx == -1){
                return {-1, -1};
            }
            return clss[nxtidx];
        }
    };
    set<int> gdl, bdl;
    set<int> gdr, bdr;
    for(int it = 0; it < q; it++){
        int a;
        cin >> a;
        set<int> curr, curl;
        auto UpdGood = [&]() {
            for(auto x : curr){
                gdr.insert(x);
            }
            for(auto x : curl){
                gdl.insert(x);
            }
            cout << "YES" << '\n';
        };
        auto UpdBad = [&]() {
            for(auto x : curr){
                bdr.insert(x);
            }
            for(auto x : curl){
                bdl.insert(x);
            }
            cout << "NO" << '\n';
        };
        int cp = a - 1, cd = -1;
        int dir = 1;
        int g = 0;
        while(cp != -1){
            tie(cp, cd) = Go(cp, cd, dir);
            if(cp == -1) {
                g = 1;
                break;
            }
            dir = !dir;
            if(dir){
                if(gdr.count(cp)){
                    g = 1;
                    break;
                }
                if(bdr.count(cp)){
                    break;
                }
                if(curr.count(cp)){
                    break;
                }
                curr.insert(cp);
            } else if(!dir){
                if(gdl.count(cp)){
                    g = 1;
                    break;
                }
                if(bdl.count(cp)){
                    break;
                }
                if(curl.count(cp)){
                    break;
                }
                curl.insert(cp);
            }
        }
        if(g){
            UpdGood();
        } else {
            UpdBad();
        }
    }
}

int32_t main() {
    // LETSGO
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}