#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fs first
#define sc second
#define pb push_back
#define int ll

const int N = 2e5 + 5;
vector<int> a(N), pres(N, 0);
int n, m, k;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            pres[i] = pres[i - 1] + a[i];
        }
        int lst = 1;
        int ans = 0;
        map<int, int> cnt;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > k)
                cnt.clear(), lst = i + 1;
            else if (a[i] == k)
            {
                while (lst <= i)
                {
                    cnt[pres[lst - 1]]++;
                    lst++;
                }
            }
            ans += cnt[pres[i] - m];
        }

        cout << ans << "\n";
    }
}