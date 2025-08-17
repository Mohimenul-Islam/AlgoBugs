#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}

const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1}; 

ll n, s, x, a[N], p[N];
//char g[N][N];

ll func(ll t)
{
	map<ll, int> hs;
	ll sum = 0; hs[0] ++;
	for(int i = 1; i <= n; i ++ ) {
		if(a[i] > t) hs.clear();
		sum += hs[p[i] - s];
		hs[p[i]] ++;
	}
	return sum;
}

void solve()
{
	cin >> n >> s >> x;
	for(int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++ ) p[i] = p[i - 1] + a[i];
	
	ll ans = func(x) - func(x - 1);
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t; cin >> t;
	while(t -- )
	solve();
	return 0;
 } 

