
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <time.h>
#include <assert.h>
#include <numeric>
#include <functional>
#include <random>
#include <iterator>
#include <bitset>
#include<valarray>
#include<fstream>
#include<unordered_map>
#include<unordered_set>
#include <filesystem>
#include <optional>
using namespace std;
typedef long long ll;

#define FOR(i, min, max) for (int i = (min); i < (max); ++i) 
#define FORE(i, min, max) for (int i = (min); i <= (max); ++i)
#define DFOR(i,max,min) for(int i=(max);i>(min);--i)
#define DFORE(i,max,min) for(int i=(max);i>=(min);--i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPE(i, n) for (int i = 0; i <= (n); ++i)
#define DREP(i, n) for (int i = (n-1); i >=0; --i) 
#define REPV(vec, i) for (int i = 0; i < (int)(vec.size()); ++i) 
#define V(type) vector<type> 
#define VV(type) vector<vector<type>>
#define VVV(type) vector<vector<vector<type>>>
#define VVVV(type) vector<vector<vector<vector<type>>>>
#define VVVVV(type) vector<vector<vector<vector<vector<type>>>>>
#define VI(type,i,n) V(type)(i,n)
#define VVI(type,i,j,n) VV(type)(i,VI(type,j,n))
#define VVVI(type,i,j,k,n) VVV(type)(i,VVI(type,j,k,n))
#define VVVVI(type,i,j,k,l,n) VVVV(type)(i,VVVI(type,j,k,l,n))
#define VVVVVI(type,i,j,k,l,m,n) VVVVV(type)(i,VVVVI(type,j,k,l,m,n))
#define ALL(v) v.begin(),v.end()
#define _S(VariableName) # VariableName
#define _D(var) cerr<<#var<<"="<<var<<endl;
template <typename Type>
void show(vector<Type> v, string sep = " ") {
	REP(i, v.size()) {
		cerr << v[i] << sep;
	}
	cerr << endl;
}
template <typename Type>
void show(VV(Type) v, string sep = " ") {
	REP(i, v.size()) {
		REP(j, v[i].size()) {
			cerr << v[i][j] << sep;
		}
		cerr << endl;
	}
	cerr << endl;
}
void print() {
	cerr << endl;
}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail)
{
	cerr << head << " ";
	// パラメータパックtailをさらにheadとtailに分割する
	print(std::forward<Tail>(tail)...);
}

template<typename T> T maxc(T& a, const T& b) { return (a = std::max(a, b)); }
template<typename T> T minc(T& a, const T& b) { return (a = std::min(a, b)); }

const std::string WHITESPACE = " \n\r\t\f\v";
string getS(string filename) {
	ifstream ifs(filename);
	if (!ifs)return "";
	string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	return str;
}
auto split(std::string str, const std::string cut) {
	std::vector<decltype(str)> data;
	for (auto pos = str.find(cut); pos != std::string::npos; pos = str.find(cut)) {
		data.push_back(str.substr(0, pos));
		str = str.substr(pos + cut.size());
	}
	if (!str.empty())data.push_back(str);
	return data;
}
std::string ltrim(const std::string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
std::string trim(const std::string& s) {
	return rtrim(ltrim(s));
}
bool ismatch(string trues, string anss) {
	vector<string> smp0 = split(trues, "\n");
	vector<string> smp1 = split(anss, "\n");
	vector<string> sm0;
	vector<string> sm1;
	for (string s : smp0) {
		string st = trim(s);
		if (st != "") {
			sm0.push_back(st);
		}
	}
	for (string s : smp1) {
		string st = trim(s);
		if (st != "") {
			sm1.push_back(st);
		}
	}
	if (sm0.size() != sm1.size())return false;
	for (int i = 0; i < sm0.size(); i++) {
		if (sm0[i] != sm1[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
vector<pair<int, T>> enumerate(vector<T>& v) {
	vector<pair<int, T>> ret(v.size());
	REP(i, v.size()) {
		ret[i] = { i,v[i] };
	}
	return ret;
}
template<typename T0, typename T1>
vector<pair<T0, T1>> zip(vector<T0>& v0, vector<T1>& v1) {
	int n = min(v0.size(), v1.size());
	vector<pair<T0, T1>> ret(n);
	REP(i, n) {
		ret[i] = { v0[i],v1[i] };
	}
	return ret;
}
ll setbit(ll& i, int j) {
	return i = i | (1LL << j);
}
void resetbit(ll& i, int j) {
	i = i & ~(1 << j);
}
bool isset(ll i, int j) {
	return (i & (1LL << j)) != 0;
}
int setbit(int& i, int j) {
	return i = i | (1LL << j);
}
void resetbit(int& i, int j) {
	i = i & ~(1 << j);
}
bool isset(int i, int j) {
	return (i & (1LL << j)) != 0;
}

int bitCount(int i) {
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i + (i >> 4)) & 0x0f0f0f0f;
	i = i + (i >> 8);
	i = i + (i >> 16);
	return i & 0x3f;
}
int bitCount(ll i) {
	int ret = 0;
	while (i != 0) {
		if (i & 1)ret++;
		i = i >> 1;
	}
	return ret;

}
void setbitxor(int& i, int j) {
	i = (i ^ (1 << j));
}
void setbitxor(ll& i, int j) {
	i = (i ^ (1LL << j));
}
ll next_combination(ll sub) {
	ll x = sub & -sub, y = sub + x;
	return (((sub & ~y) / x) >> 1) | y;
}

template<typename T>
bool candiv(T a, T b) {
	return a % b == 0;
}
template<typename T>
T llceil(T a, T b) {
	if (a % b == 0) {
		return a / b;
	}
	if (a >= 0) { return (a / b) + 1; }
	else {
		return -((-a) / b);

	}
}
template<typename T>
T llfloor(T a, T b) {
	if (a % b == 0) {
		return a / b;
	}
	if (a >= 0) { return (a / b); }
	else {
		return -((-a) / b) - 1;

	}
}
template<typename T>
bool isDuplicate(vector<T> a) {
	sort(ALL(a));
	return unique(ALL(a)) != a.end();
}
template<typename T>
bool isSameContents(vector<T> a, vector<T> b) {
	sort(ALL(a));
	sort(ALL(b));
	return a == b;
}
bool isSameContents(string a, string b) {
	sort(ALL(a));
	sort(ALL(b));
	return a == b;
}
ll llpow(ll x, ll n) {
	long long ret = 1;
	while (n > 0) {
		if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
		x *= x;
		n >>= 1;  // n を1bit 左にずらす
	}
	return ret;
}
ll safemul(ll x, ll y) {
	if (y == 0) {
		swap(x, y);
	}
	if (y == 0) {
		return 0;
	}
	if (x >= LLONG_MAX / y) {
		return LLONG_MAX;
	}
	else {
		return x * y;
	}
}
ll safeadd(ll x, ll y) {//x+y>=LLONG_MAX
	if (x >= LLONG_MAX - y) {
		return LLONG_MAX;
	}
	else {
		return x + y;
	}
}
ll llpowsafe(ll x, ll n) {
	long long ret = 1;
	while (n > 0) {
		if (n & 1) ret = safemul(ret, x);  // n の最下位bitが 1 ならば x^(2^i) をかける
		x = safemul(x, x);
		n >>= 1;  // n を1bit 左にずらす
	}
	return ret;
}
ll llpowmod(ll x, ll n, ll m) {
	long long ret = 1;
	x %= m;
	while (n > 0) {
		if (n & 1) {
			ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
			ret %= m;
		}
		x *= x;
		x %= m;
		n >>= 1;  // n を1bit 左にずらす
	}
	return ret;
}


vector<pair<ll, ll>> factorize(ll K) {
	vector<pair<ll, ll>> ans;
	for (ll i = 2; i * i <= K; i++) {
		if (K % i == 0) {
			pair<ll, ll> p(i, 0);
			while (K % i == 0) {
				p.second++;
				K /= i;
			}
			ans.push_back(p);
		}
	}
	if (K != 1) {
		ans.emplace_back(K, 1);
	}
	return ans;
}
vector<ll> divisors(ll K) {
	vector<ll> v;
	for (ll i = 1; i * i <= K; i++) {
		if (K % i != 0)continue;
		v.push_back(i);
		if (i * i != K)v.push_back(K / i);
	}
	sort(ALL(v));
	return v;
}
ll divisorsnum(ll K) {
	ll ret = 0;
	for (ll i = 1; i * i <= K; i++) {
		if (K % i != 0)continue;
		ret++;
		if (i * i != K)ret++;
	}
	return ret;
}

bool is2Graph(VV(ll)& g) {
	int N = g.size();
	vector<int> color(N, -1);
	auto dfs = [&](auto dfs, int i,int c) ->void{
		color[i] = c;
		for (auto to : g[i]) {
			if (color[to] == -1) {
				dfs(dfs, to, c ^ 1);
			}
		}
		};
	dfs(dfs, 0, 0);
	REP(i,N){
		for (auto to : g[i]) {
			if (color[i] == color[to])return false;
		}
	}
	return true;
}
void solve() {
	ll n, m;
	cin >> n >> m;	
	VV(ll)  g(n);
	REP(i, m) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	if (m != n - 1) {
		cout << 0 << endl;
		return;
	}
	if (n == 2) {
		cout << 2 << endl;
		return;
	}
	/*vector<int> num1;	
	vector<int> num2;
	int connect0 = 0;
	vector<ll> leafs;
	REP(i, n) {		
		int connect = 0;
		if (g[i].size() == 1)continue;
		ll l = 0;
		for (auto to : g[i]) {
			if (g[to].size() == 1) {				
				l++;
			}
			else {
				connect++;
			}
		}
		leafs.push_back(l);
		if (connect == 0) {
			connect0++;
		}else if (connect==1) {
			num1.push_back(i);
		}
		else if (connect == 2) {
			num2.push_back(i);
		}
		else {
			cout << 0 << endl;
			return;
		}
	}	
	ll mod = 1000000007;
	vector<ll> kai(n + 1);
	kai[0] = 1;
	kai[1] = 1;
	for (ll i = 2; i <= n; i++) {
		kai[i] = i * kai[i - 1];
		kai[i] %= mod;
	}
	ll ans = 1;
	for(auto l:leafs) {
		ans *= kai[l];
		ans %= mod;
	}	
	if (connect0) {
		assert(connect0 == 1);
		assert(num1.size() == 0);
		cout << (ans * 2) % mod << endl;
	}
	else {
		assert(num1.size() == 2);
		cout << (ans * 4) % mod << endl;
	}*/
	ll mod = 1000000007;
	vector<ll> kai(n + 1);
	kai[0] = 1;
	kai[1] = 1;
	for (ll i = 2; i <= n; i++) {
		kai[i] = i * kai[i - 1];
		kai[i] %= mod;
	}
	vector<bool> isleaf(n);
	REP(i, n) {
		isleaf[i] = (g[i].size() == 1);
	}
	auto dfs=[&](auto dfs, int from, int pre = -1) -> ll{
		ll ret = 1;
		ll leafnum = 0;
		for (auto to : g[from]) {
			if (to != pre){
				if (isleaf[to] == false) {
					ret *= dfs(dfs, to, from);
					ret %= mod;
				}
				else {
					leafnum++;
				}
			}
		}
		ret *= kai[leafnum];
		ret %= mod;
		return ret;
	};
	ll ans = 0;
	REP(i, n) {
		if (isleaf[i] == false) {
			ans=dfs(dfs, i);
			break;
		}
	}
	int notleafnum = 0;
	REP(i, n) {
		if (isleaf[i] == false) {
			notleafnum++;
		}
	}
	if (notleafnum == 1) {
		ans *= 2;
		ans %= mod;
	}
	else {
		ans *= 4;
		ans %= mod;
	}
	cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	REP(i, t) {
		solve();
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////
