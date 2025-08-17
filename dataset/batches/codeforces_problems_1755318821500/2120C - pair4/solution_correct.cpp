#include <bits/stdc++.h>
#define int long long
#define f first
#define s second

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    if(m < n || m > (n * (n + 1)) / 2){
        cout << -1;
        return;
    }
    vector<int> a(n);
    set<int> p;
    for(int i = 1; i <= n; ++i) p.insert(i);
    bool flag = false;
    for(int i = 0; i < n; ++i){
        if(flag){
            a[i] = *p.begin();
            p.erase(p.begin());
        }else{
            if(n - i >= m - (n - i) + 1){
                a[i] = m - (n - i) + 1;
                p.erase(m - (n - i) + 1);
                flag = true;
            }else{
                a[i] = n - i;
                p.erase(n - i);
                m -= n - i;
            }
        }
    }
    cout << a[0] << '\n';
    for(int i = 0; i < n - 1; ++i){
        cout << a[i] << ' ' << a[i + 1] << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
}