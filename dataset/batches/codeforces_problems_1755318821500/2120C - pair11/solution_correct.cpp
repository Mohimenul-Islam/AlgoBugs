#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    // freopen("E:/kafuyuno/code/c++/contests/test1i.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        if(m < n || m > (n + 1) * n / 2){
            cout << "-1\n";
            continue;
        }
        vector<int>rst(n);
        vector<bool>vst(n + 1);
        ll idx = 0, now = n, sum = n;
        for(ll i = n - 1; i > 0; i--){
            if(sum + i >= m){
                ll num = m - sum + 1;
                rst[idx++] = num;
                vst[num] = true;
                break;
            }
            else{
                rst[idx++] = now;
                vst[now--] = true;
                sum += now * 1ll;
            }
        }
        for(int i = 1;i <= n; i++){
            if(!vst[i]){
                rst[idx++] = i;
            }
        }
        cout << rst[0] << endl;
        for(int i = 1; i < rst.size(); i++){
            printf("%d %d\n", rst[i - 1], rst[i]);
        }
    }
    return 0;
}
/*
-1
3
3 1
1 2
2 4
-1
0
0 0
0 2
2 3
1
1 2
2 3
3 4

*/