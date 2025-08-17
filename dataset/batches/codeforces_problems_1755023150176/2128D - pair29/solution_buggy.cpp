#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int NR = 5e5 + 10;
int a[NR];
int f[NR];

int main()
{
    int T;
    scanf("%d", &T);
    while (T --)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i ++)
        {
            f[i] = 1;
        }
        if (a[1] > a[2]) f[2] = 3;
        else f[2] = 2;
        for (int i = 3; i <= n; i ++)
        {
            int j = (a[i - 1] > a[i]) ? i - 1 : i - 2;
            f[i] += f[j] + j + (j == (i - 2));
        }
        long long ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            ans += f[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}