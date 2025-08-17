#include<bits/stdc++.h>
#include<string>
#define PII pair<int,int>
#define whatis(x) cout<<(#x)<<" is "<<(x)<<'\n';
#define show(arr) for (auto i: arr) cout<<i<<' '; cout<<'\n';
#define tag cout<<"tag"<<endl;
#define at(item,p) item[p.first][p.second]
#define modify(item,p,val) item[p.first][p.second]=val;
#define print(x) cout<<(x);
#define spair(pair) cout<<pair.first<<' '<<pair.second<<'\n';
#define PBB pair<bool,bool>
#define PLL pair<long long, long long>
#define F first
#define S second
#define ar3 array<int,3>
#define ar2 array<int,2>
#define ar4 array<int,4>
#define scase solve();
#define mcase int t;cin>>t;while(t--)solve();
#define PLI pair<ll, int>
#define quit(message) {cout<<#message<<'\n';return;}
using namespace std;
typedef long long ll;
char newline='\n';
char space=' ';
int MOD = 1e9 + 7;
int MOD2 = 1e9 + 6;

struct edge {
    int a, b;
    edge(){}
    edge(int x, int y): a(x), b(y) {}
};



void solve() {
    int n,s,x;cin>>n>>s>>x;
    map<ll, ll> rec;
    int arr[n];
    for (int&i:arr)cin>>i;
    ll ans = 0;
    int lef=0;
    ll pref[n+1];
    pref[0]=0;
    for (int i=0;i<n;++i) {
        int cur = arr[i];
        if (cur > x) {
            rec.clear();
            lef = i+1;
            continue;
        }
        if (cur == x) {
            while (lef <= i) ++rec[pref[lef++]];
        }
        pref[i+1]=pref[i]+cur;
        ans += rec[pref[i+1] - s];
    }
    cout<<ans<<'\n';

}



int main(){
    // fstream file("input.txt");
    // cin.rdbuf(file.rdbuf());


    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mcase

}
