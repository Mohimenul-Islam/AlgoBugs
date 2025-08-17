#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>
#include <set>
#include <numeric>
#include <random>
#include <functional>
#include <bit>
#include <bitset>
#include <cassert>
using namespace std;
using u64 = unsigned long long;
using u32 = unsigned;
using i64 = long long;
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(a)         \
    cout << #a << "=";    \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
#define bin8(x) cout << #x << "=" << bitset<8>(x) << endl;
#define rd read()
#define int long long
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, pair<int, int>> PIII;
typedef pair<LL, LL> PIIL;
const int N = 200, INF = 0x3f3f3f3f, mod = 998244353;
inline LL read()
{
    LL x = 0, y = 1;
    char c = getchar();
    while (c > '9' || c < '0')
    {
        if (c == '-')
            y = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * y;
}
inline void solve()
{
    int n = rd, m = rd;
    if(m<n||m>n*(n+1)/2){
        cout<<-1<<endl;;
        return;
    }
    vector<int> a;
    int now=n;
    vector<bool>st(n + 1);
    for (int i = n; i >= 2&&now<m;i--){
        if(now+i-1<=m){
            a.push_back(i);
            st[i] = true;
            now += i - 1;
        }
    }
    a.push_back(1), st[1] = 1;
    // vdebug(a);
    cout << a[0] << endl;
    for(int i=1;i<=n;i++){
        if(st[i]&&i!=a[0]){
            cout << a[0] << " "<<i<<endl;
        }
        else if(!st[i]){
            cout << 1 << ' ' << i << endl;
        }
    }
}
signed main()
{
    int T = 1;
    T = rd;
    while (T--)
    {
        solve();
    }
}
