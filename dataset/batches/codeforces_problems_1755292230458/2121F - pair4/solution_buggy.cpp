// #define ONLINE_JUDGE


#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

// #ifndef ONLINE_JUDGE

// #include "../pch.h"
// #include "diff.cpp"

// #endif


using namespace __gnu_pbds;
using namespace std;

/*greater_equal means decreasing ordered_multiset.
use less_than for normal ordered_set*/
template<class T> using ordered_set = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Operator overloads
template<typename T1, typename T2>
// cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T>
// cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it: v)cin >> it;
    return istream;
}

template<typename T1, typename T2>
// cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

template<typename T>
// cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it: c) cout << it << " ";
    return ostream;
}

#define getunique(v) do { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); } while(0)

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pyes  cout << "YES" << endl;
#define pno  cout << "NO" << endl;

#define all(s) s.begin(), s.end()

#define fast  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


using ll = long long;
const ll inf = 1e18;
const ll MOD = 1000000000 + 7;
const ll MOD1 = 998244353;

typedef pair<long long, long long> pll;

#define pbob cout<<"Bob"<<endl;
#define pali cout<<"Alice"<<endl;
#define pdraw cout<<"Draw"<<endl;

void precomp() {

}
void solve() {
    ll n, sum, max;
    cin>>n>>sum>>max;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    vector<ll> pref = v;
    for(int i = 1; i < n; i++){
        pref[i] += pref[i - 1];
    }
    pref.insert(pref.begin(), 0);
    int l = 0;
    multiset<ll> st;
    ll currIndex = 0;
    ll ans = 0;
    bool valid = false;
    ll lastadded = 0;
    while(currIndex < n){
        if (v[currIndex] > max) {
            st.clear();
            lastadded = currIndex + 1;
        }else if (v[currIndex] == max) {
            for (int i = lastadded; i <= currIndex; i++) {
                st.insert(pref[i]);
            }
            ll needed = pref[currIndex + 1] - sum;
            ans += st.count(needed);
            lastadded = currIndex + 1;
        }else {
            ll needed = pref[currIndex + 1] - sum;
            ans += st.count(needed);
        }
        currIndex++;
    }
    cout<<ans<<endl;
}



int32_t main() {
    fast;
// #ifdef ONLINE_JUDGE
//     freopen("threesum.in", "r", stdin);
//     freopen("threesum.out", "w", stdout);
// #endif

#ifndef ONLINE_JUDGE
    clock_t begin = clock();
    ifstream input("input.txt");
    ofstream outfile("output.txt");
    if (!input.is_open()) {
        cout << "Failed to open input file." << endl;
        return 1;
    }
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outfile.rdbuf());
#endif
    precomp();
    ll t = 1;
    cin >> t;


    while (t--) {
        solve();
    }


#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n\nExecuted In:" << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms\n";
    cin.rdbuf(cinbuf);
    input.close();
    cout.rdbuf(coutbuf);
    outfile.close();
//    compareFiles("output.txt", "expected.txt");

#endif

    return 0;
}