#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int inv_mod(int M , int n){
    int a[2] = {1 , 0};
    int b[2] = {0 , 1};
    int d = n;
    int D = M;
    int x , y , r , q;

    do{
        r = D % d;
        q = (D - r) / d;

        x = a[0] - q * b[0];
        y = a[1] - q * b[1];

        a[0] = b[0];
        a[1] = b[1];
        b[0] = x;
        b[1] = y;
        
        D = d;
        d = r;

    } while(r != 1);
    
    b[1] = (b[1] < 0 ? M + b[1] : b[1]);
    
    return b[1];
}

#define M 1000000007

bool checkCycle(int u , int v , vector<int>&visited , vector<vector<int>>&adj_list){
    if(visited[v]) return true;
    
    visited[v] = 1;
    bool f = false;

    for(auto p:adj_list[v]){
        if(p != u){
            f |= checkCycle(v , p , visited , adj_list);
        }
    }

    return f;
}

ll ftl(int i){
    ll ans = 1;
    while(i > 0){
        ans *= i;
        ans %= M;
        i--;
    }
    
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n , k;
        cin >> n >> k;
        vector<vector<int>>v(n + 1);
        vector<int> childs(n + 1 , 0);
        vector<int> degree(n + 1 , 0);
        vector<int> visited(n + 1 , 0);
        
        for(int i = 0;i < k;i++){
            int a , b;
            cin>> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        
        ll ans = 2;
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(degree[i] == 1){
                childs[v[i][0]]++;
            }
            else if(degree[i] > 1) cnt++;
        }
        if(cnt > 1) ans = 4;

        for(int i = 1;i <= n;i++){
            ans = (ans * ftl(childs[i])) % M; 
        }

        int f = 0;
        ans = (!checkCycle(0 , 1 , visited , v) ? ans : 0);
        
        for(int i = 1;i <= n;i++){
            if(!visited[i]){
                ans = 0;
                break;
            }
        }

        for(int i =1;i <= n;i++){
            int cnt = 0;
            if(degree[i] > 1){
                for(auto p:v[i]) cnt += (degree[p] > 1 ? 1 : 0);
            }
            if(cnt > 2) ans = 0;
        }

        if(ans == 0) cout << 0 << '\n';
        else cout << (ans * ftl(f)) % M << "\n";

    }
    return 0;
}

