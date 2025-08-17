#include <bits/stdc++.h>
using namespace std;

/// #DEFINEs
#define int long long
#define f first
#define s second
#define lb lower_bound
#define up upper_bound
#define pb push_back
#define pf push_front
#define sz size()
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)

#define all(a) a.begin(), a.end()
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
#define lg2(x) __lg(x)
#define fl "\n"
#define YN(x) cout << ((x) ? ("YES") : ("NO")) << fl;

/// TYPEDEFs
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<bool> vb;

/// CONSTANTS
const int oo = 1e9 + 5;
const ll OO = (ll)1e18 + 5;
const ld pi = acos(-1.0);

/// CONSTRAINTS
const int maxn = 2e5 + 5;
int mod = 1e9 + 7;
const ld eps = 1e-9;

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

/// +--------------------------------------+ CODE +--------------------------------------+
void solve()
{
    int n, sum, x;
    cin >> n >> sum >> x;
    vi vec(n);
    fori(n) cin >> vec[i];
    int cur_sum = 0;
    int idx = -1;
    map<int, vi> mapi;
    mapi[0].pb(0);
    int answ = 0;
    fori(n)
    {
        if (vec[i] > x)
        {
            mapi.clear();
            mapi[0].pb(0);
            idx = -1;
            cur_sum = 0;
            continue;
        }
        if (vec[i] == x)
            idx = i;
        cur_sum += vec[i];
        mapi[cur_sum].pb(i + 1);
        if (mapi.find(cur_sum - sum) != mapi.end())
        {
            auto it = upper_bound(all(mapi[cur_sum - sum]), idx);
            answ += it - mapi[cur_sum - sum].begin();
            // cout << answ << " " << cur_sum << " " << fl;
        }
    }

    cout << answ << fl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.precision(8);
    // cout << fixed;
    int testcases = 1;
    cin >> testcases;
    while (testcases--)
        solve();
}