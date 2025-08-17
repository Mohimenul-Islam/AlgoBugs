#include <bits/stdc++.h>
using namespace std;
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define pb push_back
#define pob pop_back
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
 
void setIO(){
    #ifndef ONLINE_JUDGE
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
}

const long long mod = 1e9 + 7;

struct point{
    int x, y;
    int pos;
};

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); setIO();
    int t; cin >> t;
    while(t--){
        int n; long long m; cin >> n >> m;

        if(m < n || m > n*(n+1)/2){
            cout << -1 << "\n";
            continue;
        }

        long long p = m - n;
        long long current = 0;
        long long nsum = 0;
        vector<int> ans;

        for(int i = n - 1; i >= 0; i--){
            if(current == p) break;
            if(current + i <= p){
                current += i;
                ans.push_back(i+1);
                nsum += i + 1;
            }
        }

        nsum += n - ans.size();
        while(ans.size() != n){
            ans.push_back(1);
        }

        if(n == m){
            cout << 1 << "\n";
            for(int i = 1; i < n; i++){
                cout << i << " " << i + 1 << "\n";
            }
            continue;
        }

        vector<bool> visited(n + 1, true);
        cout << ans[0] << "\n";
        visited[ans[0]] = false;

        for(int i = 0; i < n - 1; i++){
            cout << ans[i] << " " << ans[i+1] << "\n";
            visited[ans[i]] = visited[ans[i+1]] = false;
            if(ans[i+1] == 1) {
                int prev = 1;
                for(int j = 2; j <= n; ++j) {
                    if(visited[j]) {
                        cout << prev << " " << j << '\n';
                        prev = j;
                    }
                }
                break;
            }
        }

    }
    return 0;
}