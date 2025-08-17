/*
s = 7 
x = 3

  0 -1 3 3 3 4  1  2  2  3  0 0  3
0 0 -1 2 5 8 12 13 15 17 20 20 19 22
                         l

cnt
cnt[13] = 1
cnt[15] = 1
cnt[17] = 1


*/

# include <bits/stdc++.h>
using namespace std;
# define int long long 

const int MAXN = 200000;
int node[4*MAXN + 5], arr[MAXN+5];
const int INF = 1e18;
int n;

void solve(){
    int s, x;
    cin >> n >> s >> x;
    int psum[n+1];
    psum[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    map<int, int> cnt;
    int l = 0, ans = 0;
    for(int i=1; i<=n; i++){
        if(arr[i] == x){
            while(l < i) cnt[psum[l]]++, l++;
        }
        else if(arr[i] > x){
            cnt.clear();
            l = i;
        }
        int t = psum[i] - s;
        ans += cnt[t];
    }
    
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}