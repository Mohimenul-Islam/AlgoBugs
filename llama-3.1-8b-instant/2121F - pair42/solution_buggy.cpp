#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define popc(x) __builtin_popcountll(x)
#define dbg(x) cerr << #x << " = " << x << endl;
#define debug(v) cerr << #v << " = ["; for(auto x : v) cerr << x << " "; cerr << "]\n";
#define debug_p(v) cerr << #v << " = ["; for (auto &p : v) cerr << "(" << p.first << "," << p.second << ") "; cerr << "]\n";
#define debug_vv(v) do { cerr << #v << " = {"; bool f = 1; for (auto &r : v) { cerr << (f ? "{" : "    {"); f = 0; for (size_t i = 0; i < r.size(); ++i) cerr << r[i] << (i+1 < r.size() ? ", " : ""); cerr << "}\n"; } cerr << "}\n"; } while(0)
const long long LLong_MAX = 9223372036854775807;
const ll mod = 1e9 + 7;
/*---------------------------------------------------------------------------------------------------------------------------*/
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll m) {return expo(a, m - 2, m);}   // m is prime
ll ceil_div(ll a, ll b) { return (a + b - 1) / b;}
ll combination(ll n, ll r, ll m, ll fact[], ll ifact[]) { return (((fact[n] * ifact[n - r]) % m) * ifact[r]) % m; }
bool isInteger(double lol) { return fabs(lol - round(lol)) < 1e-9; }
bool isPrime(ll n) { if (n < 2) return false; if (n == 2 || n == 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
vector<ll> sieve(ll n) { ll*arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
vector<ll> divisor(ll n) { std::vector<ll> d; for (ll i = 1; i * i <= n; i++) if (n % i == 0) { d.push_back(i); if (i != n / i) d.push_back(n / i); } std::sort(d.begin(), d.end()); return d; }
/*---------------------------------------------------------------------------------------------------------------------------*/
struct Node {
    int sum = 0;
    int maxi = LLONG_MIN;
    int mini = LLONG_MAX;
};

class Segtree {
public:
    int n;
    vector<Node> tree;
    vector<int> lazyAdd, lazySet;
    vector<bool> isSet;

    Segtree(int size) {
        n = size;
        tree.resize(4 * n);
        lazyAdd.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);
        isSet.assign(4 * n, false);
    }

    void build(const vector<int>& a, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (tl == tr) {
            tree[v].sum = tree[v].maxi = tree[v].mini = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        pull(v);
    }

    void push(int v, int tl, int tr) {
        if (isSet[v]) {
            applySet(v, lazySet[v], tl, tr);
            if (tl != tr) {
                isSet[2 * v] = isSet[2 * v + 1] = true;
                lazySet[2 * v] = lazySet[2 * v + 1] = lazySet[v];
                lazyAdd[2 * v] = lazyAdd[2 * v + 1] = 0; // clear add
            }
            isSet[v] = false;
        }
        if (lazyAdd[v] != 0) {
            applyAdd(v, lazyAdd[v], tl, tr);
            if (tl != tr) {
                lazyAdd[2 * v] += lazyAdd[v];
                lazyAdd[2 * v + 1] += lazyAdd[v];
            }
            lazyAdd[v] = 0;
        }
    }

    void applySet(int v, int val, int tl, int tr) {
        tree[v].sum = val * (tr - tl + 1);
        tree[v].maxi = tree[v].mini = val;
        lazyAdd[v] = 0; // reset addition
    }

    void applyAdd(int v, int add, int tl, int tr) {
        tree[v].sum += add * (tr - tl + 1);
        tree[v].maxi += add;
        tree[v].mini += add;
    }

    void pull(int v) {
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        tree[v].maxi = max(tree[2 * v].maxi, tree[2 * v + 1].maxi);
        tree[v].mini = min(tree[2 * v].mini, tree[2 * v + 1].mini);
    }

    void rangeAdd(int l, int r, int add, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        push(v, tl, tr);
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            lazyAdd[v] += add;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        rangeAdd(l, r, add, 2 * v, tl, tm);
        rangeAdd(l, r, add, 2 * v + 1, tm + 1, tr);
        pull(v);
    }

    void rangeAssign(int l, int r, int val, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        push(v, tl, tr);
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            isSet[v] = true;
            lazySet[v] = val;
            lazyAdd[v] = 0; // clear add
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        rangeAssign(l, r, val, 2 * v, tl, tm);
        rangeAssign(l, r, val, 2 * v + 1, tm + 1, tr);
        pull(v);
    }

    Node query(int l, int r, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        push(v, tl, tr);
        if (r < tl || tr < l) return {0, LLONG_MIN, LLONG_MAX};
        if (l <= tl && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        Node left = query(l, r, 2 * v, tl, tm);
        Node right = query(l, r, 2 * v + 1, tm + 1, tr);
        return {
            left.sum + right.sum,
            max(left.maxi, right.maxi),
            min(left.mini, right.mini)
        };
    }

    /*
        segtree st(N);

        st.build(arr);

        st.rangeAdd(1, 3, 10)    --> adds
        st.rangeAssign(2, 5, 9)  --> assign

        Node ans = st.query(4, 8);

        maximum = ans.maxi
        minimum = ans.mini
        sum     = ans.sum
     */

};

int fk(vector<int>& val, int x, int r, Segtree &st) {
    // total elements with maximum == x
    // FFFFTTTT
    int n = val.size();
    int lo = 0, hi = n - 1;
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        // dbg(val[mid])
        Node idk = st.query(val[mid] + 1, r);
        // cout << idk.maxi << ' ';
        int maxx = idk.maxi;
        if (maxx > x) {
            lo = mid + 1;
        }
        else if (maxx == x) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            hi = mid - 1;
        }
    }

    // cout << ans << ' ';
    if (ans == -1) return 0;
    else return (n - (ans + 1) + 1);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, s, x; cin >> n >> s >> x;
        vector<int> arr(n);
        for (auto &it : arr) cin >> it;
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + arr[i];

        Segtree st(n);
        st.build(arr);

        map<int, vector<int>> mp;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int curr = pre[i];
            int req = pre[i] - s;

            if (pre[i] == s) {
                Node idk = st.query(0, i);
                if (idk.maxi == x) {
                    cnt++;
                    // cout << "ojo";
                }

            }

            if (mp[req].size() > 0) {
                dbg(cnt);
                dbg(i)
                debug(mp[req])
                cnt += fk(mp[req], x, i, st);
            }

            mp[pre[i]].pb(i);
        }

        cout << cnt << endl;

    }
}

