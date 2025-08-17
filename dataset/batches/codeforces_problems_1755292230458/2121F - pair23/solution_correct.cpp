#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

// no. of subarrays whose sum is s and all the elements are <= x
int func(int n, int s, int x, vector<int> &a)
{
    map<int, int> mp;
    mp[0] = 1;

    int ans = 0, curr_s = 0;
    for (int r = 0; r < n; r++)
    {
        if (a[r] > x)
        {
            mp.clear();
            mp[0] = 1;

            curr_s = 0;
            continue;
        }

        curr_s += a[r];
        ans += mp[curr_s - s];
        mp[curr_s]++;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, s, x;
        cin >> n >> s >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = func(n, s, x, a) - func(n, s, x - 1, a);
        cout << ans << endl;
    }
    return 0;
}
