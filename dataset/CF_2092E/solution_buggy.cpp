#define _CRT_SECURE_NO_WARNINGS

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("O3")

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("bmi,bmi2,popcnt,lzcnt")

//Babahnineeleven will win IOI 2040
//Tanya Zadniprovska will win EGOI 2025
//Andrew Holod will NOT win IOI 2025
//Andrew Holod did not qualify to IOI 2025))))))))))
//Andrew Pavlyk is best coder in Khmelnytskiiii

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <fstream>
#include <climits>
#include <queue>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <cstring> // Ð�Ð»Ñ� memset

using namespace std;

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair <int, int> pii;
typedef std::pair <ll, ull> piu;
typedef std::pair <ld, ld> pdd;

const ll DIM = 200007;
const ld PI = 3.14159265358979;
const ll SQDIM = 450;
const ll MXMASK = (1 << 20);
const ll INF = 4e18;
const ll mod = 1e9 + 7;
const ld eps = 1e-18;
const ld gr = (sqrt(5) + 1) / 2;
const ll Bits = 32;
const ll Bsize = 300;
const char endL = '\n';

const ll dx[4] = { 1, 0, -1, 0 };
const ll dy[4] = { 0, 1, 0, -1 };

FILE* stream;

ll f(ll a) {
	if (a == 0) return 1;
	if (a % 2 == 0) {
		ll x = f(a / 2);
		return (x * x) % mod;
	}
	else {
		ll x = f(a / 2);
		return (2 * x * x) % mod;
	}
}

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;

	ll frameBlack = 0, frameWhite = 0, insideGrean = (n - 2) * (m - 2) + 4;
	for (int i = 1; i <= k; i++) {
		int x, y, col;
		cin >> x >> y >> col;

		if (x == 1 || x == n || y == 1 || y == m) {
			if (x == 1 && y == 1) insideGrean--;
			else if (x == 1 && y == m) insideGrean--;
			else if (x == n && y == 1) insideGrean--;
			else if (x == n && y == m) insideGrean--;
			else {
				if (col == 0) {
					frameWhite++;
				}
				if (col == 1) {
					frameBlack++;
				}
			}
		}
		else {
			insideGrean--;
		}
	}

	int res = 0;

	ll selection = 2 * n + 2 * m - 8;
	selection -= frameBlack;
	selection -= frameWhite;

	if (selection == 0 && frameBlack % 2 == 1) {
		cout << 0 << endl;
		return;
	}

	if(selection != 0) res += selection - 1;
	res += insideGrean;

	cout << f(res) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef _DEBUG
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;

}