
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define mat vector<vector<int>>
#define all(v) (v).begin(), (v).end()
int inf = 1e18;
int mod = 1e9 + 7;
int bs1(vii &v, int k, int j)
{
    int a = -1, l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m].ff == k)
        {
            if (v[m].ss >= j)
            {
                a = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else if (v[m].ff > k)
        {
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return a;
}
int bs2(vii &v, int k, int j)
{
    int a = -1, l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m].ff == k)
        {
           if (v[m].ss >= j)
            {
                a = m;
                l = m + 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else if (v[m].ff > k)
        {
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return a;
}
int find(const vi &v, const int &sum, const int &x, int start, int n)
{
  
    vi p;
    int cr = 0, r = -1, a = 0;
    vii pre;
    for (int i = start; i < n; i++)
    {
        if (v[i] == x)
        {
            r = i;
            p.pb(i);
        }
        cr += v[i];
        if (r != -1)
        {
            pre.pb({cr, i});
            if(cr==sum)a++;
        }
    }
    if (r == -1)
        return 0;
    sort(all(pre));
    cr=sum;
    for (int i = start; i < r; i++)
    {
        cr += v[i];
        auto k=upper_bound(all(p),i);
        if(k==p.end())continue;
        int b1 = bs1(pre, cr, *k),b2=bs2(pre,cr,*k);
        if(b1!=-1){
            a+=(b2-b1+1);
        }
        
        
    }
    return a;
}
void solve()
{
    int n, sum, x;
    cin >> n >> sum >> x;
    vi v(n);
    for (auto &y : v)
        cin >> y;
    int ans = 0, start = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > x && start != -1)
        {
            ans += find(v, sum, x, start, i);
            start = -1;
        }
        else if (v[i] <= x && start == -1)
        {
            start = i;
        }
    }
    if (start != -1)
    {
        ans += find(v, sum, x, start, n);
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs--)
    {
        solve();
    }
}