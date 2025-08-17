#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i ,a ,b) for(int i =a;i<=b;++i)
#define endl '\n'
#define debug(a) cout<<#a<<'='<<a<<endl;
#define inf 0x3f3f3f3f
#define ls u<<1
#define rs u<<1|1
typedef pair<int,int> pii;
const int N =2e5+9;
const int mod = 1e9+7;
int n , m;
vector<int>g[N];
int pre[N];
int ans = 1;
bool f =1;
void dfs(int u ,int fa , int cnt){
    if(!f)return;
    int cnt1 = 0 ,cnt2 = 0;
    
    if((int)g[u].size() == 1){
        return;
    }
    for(auto v :g[u]){
        if(fa == v)continue;
        if(g[v].size() > 1){
            cnt2++;
            cnt2 %=mod;
        }
        else{
            cnt1++;
             cnt1 %=mod;
        }
    }
    if(cnt == 1){
        if(cnt2 > 2){
             f= 0;
            return;
        }
       
    }
    else{
        if(cnt2 > 1){
            f = 0;
            return;
        }
    }

    if(cnt1 > 0){
        ans *= pre[cnt1];
        ans %=mod;
    }

    for(auto v :g[u]){
        if(v == fa)continue;
        if(g[v].size() > 1)dfs(v , u ,cnt+1);
    }
}

void solve(){
    cin>>n>>m;
    rep(i , 1 , n)g[i].clear();
    ans = 1;
    f = 1;
    rep(i ,1 ,m){
        int u ,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(m != n-1){
        cout<<0<<endl;
        return;
    }
    int rt = 1;
    rep(i ,1 , n){
        if(g[i].size() > 1){
            rt = i;
        }
    }
    dfs(rt , 0 , 1);
    if(!f){
        cout<<0<<endl;
        return;
    }
    ans *=2;
    ans %=mod;

    int t = 0;
    rep(i ,1 ,n){
        if(g[i].size() > 1){
            t++;
        }
    }
    if(t > 1){
        ans *=2;
        ans %=mod;
    }


    cout<<ans<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    pre[0] = 1;
    pre[1] = 1;
    rep(i ,2 , N){
        pre[i] = pre[i-1]*i;
        pre[i] %=mod;
    }
    
    int _ = 1;
    cin>>_; 
    while(_--)solve();
    return 0;
}