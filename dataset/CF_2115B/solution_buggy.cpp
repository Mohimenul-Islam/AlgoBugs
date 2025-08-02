#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII array<int, 2>

const int inf = 4e18;
const int N = 3e5 + 5;
int T, n, q;
int arr[N], brr[N], crr[N];
int x[N], y[N], z[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // T = 1;
    cin >> T;
    while (T--)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> brr[i];
            arr[i] = brr[i];
        }
        for (int i = 1; i <= q; i++)
            cin >> x[i] >> y[i] >> z[i];
        for (int i = q; i >= 1; i--)
        {
            if (arr[x[i]] < arr[z[i]])
                arr[x[i]] = arr[z[i]];
            if (arr[y[i]] < arr[z[i]])
                arr[y[i]] = arr[z[i]];
        }
        for (int i = 1; i <= n; i++)
            crr[i] = arr[i];
        for (int i = 1; i <= q; i++)
            crr[z[i]] = min(crr[x[i]], crr[y[i]]);
        bool valid = 1;
        for (int i = 1; i <= n; i++)
            valid &= (brr[i] == crr[i]);
        if (valid)
            for (int i = 1; i <= n; i++)
                cout << arr[i] << ' ';
        else
            cout << -1;
        cout << '\n';
    }
    return 0;
}