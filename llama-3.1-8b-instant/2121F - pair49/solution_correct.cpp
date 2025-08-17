// ЛУЧШАЯ КОРНЕВАЯ
//

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("inline")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
ll inf = 1000000000LL;
ll mod = 1000000000 + 7;
vector<unordered_map<ll, int>> block_cnt;
vector<int> mas;
vector<ll> pref;
const ll rasm = 450;

void build() {
    for (int i = 1; i < pref.size(); i++) {
        block_cnt[(i - 1) / rasm][pref[i]]++;
    }
}

ll get(ll l, ll r, ll num) {
    ll res = 0;
    while (l <= r) {
        if (l % rasm == 0 and l + rasm - 1 <= r) {
            res += block_cnt[l / rasm][num];
            l += rasm;
        } else {
            res += (pref[l + 1] == num);
            l++;
        }
    }
    return res;
}

void solve() {
    ll n, s, x;
    cin >> n >> s >> x;
    mas = vector<int>(n);
    pref = vector<ll>(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
        pref[i + 1] = pref[i] + mas[i];
    }
    mas.clear();
    multiset<int> se1;
    multiset<int> se2;
    map<ll, int> mapa;
    ll l1 = 0;
    ll r1 = 0;
    ll res = 0;
    for (int l = 0; l < n; l++) {
        if (r1 < l1) {
            r1 = l1;
            mapa.clear();
            mapa[pref[l1 + 1]]++;
        }
        if (l == 0) {
            se1.insert(mas[0]);
            se2.insert(mas[0]);
            mapa[pref[1]]++;
        }
        if (l != 0) {
            se1.extract(mas[l - 1]);
            se2.extract(mas[l - 1]);
        }
        while ((se1.empty() or *--se1.end() < x) and l1 < n - 1) {
            l1++;
            mapa[pref[l1]]--;
            if (mapa[pref[l1]] == 0) {
                mapa.erase(pref[l1]);
            }
            se1.insert(mas[l1]);
        }
//        while (r1 < l1) {
//            r1++;
//            se2.insert(mas[r1]);
//            mapa[pref[r1+1]]++;
//        }
        while ((se2.empty() or *--se2.end() <= x) and r1 < n - 1) {
            r1++;
            se2.insert(mas[r1]);
            mapa[pref[r1 + 1]]++;
            if (*--se2.end() > x) {
                se2.extract(*--se2.end());
                mapa[pref[r1 + 1]]--;
                if (mapa[pref[r1 + 1]] == 0) {
                    mapa.erase(pref[r1 + 1]);
                }
                r1--;
                break;
            }
        }
        if (!se1.empty() and !se2.empty() and *--se2.end() == x and *--se1.end() == x) {
            res += mapa[s + pref[l]];
        }
    }
    cout << res << '\n';
    block_cnt.clear();
    pref.clear();
    se2.clear();
    se1.clear();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cout.precision(12);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
