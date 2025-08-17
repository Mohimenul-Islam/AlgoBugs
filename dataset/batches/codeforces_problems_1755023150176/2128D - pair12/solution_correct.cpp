#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; 
#define int long long
#define MOD 1000000007
#define MOD1 998244353
const int N = 100010;
int inf = 1e9;

#define ff first
#define ss second
using pi = pair<int,int>;
using state1 = pair<pair<int,int>,int>;
using state2 = pair<int,pair<int,int>>;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define pb push_back
#define po pop_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define nline cout<<'\n';
#define all(x) x.begin(),x.end()
#define allrev(x) x.rbegin(),x.rend()
#define output(x) cout<<x<<'\n';
#define loop(i, start, end) for(int i = start;i<end;++i)
#define looprev(i, start, end) for(int i = end;i>=start;i--)

template<typename T> void read(T& x) { cin >> x; }
template<typename T, typename... Args>
void read(T& first, Args&... rest) {
    cin >> first;
    read(rest...);
}
template<typename T> void read(vector<T>& v) { for (auto &x : v) cin >> x; }
template<typename T> void print(const vector<T>& v) { for (auto &x : v) cout << x << " "; cout << endl; }
 

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
// os.order_of_key(x) {find the index of value x}, *os.find_by_order(x) {value at index x};
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

void solve()
{
    int n;cin>>n;
    vi arr(n);
    loop(i,0,n)cin>>arr[i];
    vector<int>ans(n,0);
    ans[0] = 1;
    for(int i = 1;i<n;i++){
        if(arr[i]<arr[i-1]){
            ans[i] += ans[i-1];
            ans[i] += (i+1);
        }else{
            ans[i] += ans[i-1]+1;
        }
    }         
    int sum = accumulate(all(ans), 0ll);
    cout<<sum<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T_T;cin>>T_T;
    while(T_T--)
        solve();
    return 0;
}