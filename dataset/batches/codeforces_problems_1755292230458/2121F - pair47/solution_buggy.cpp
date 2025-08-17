#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define double long double
#define vin vector<int>
#define mai map<int,int>
#define ar2 array<int,2>
#define ar3 array<int,3>
#define ar4 array<int,4>
#define ar5 array<int,5>
#define var2 vector<ar2>
#define var3 vector<ar3>
#define var4 vector<ar4>
//#define mod 998244353
#define mod 1000000007

void solve(){
    int n,s,x;
    cin >> n >> s >> x;
    vin a(n+1,0);
    map<int,int> kn;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        kn[a[i]]++;
    }
/*    if (kn[0]==n){
        if (s==0 && x==0){
            cout << n*(n+1)/2;
            return;
        }
    }*/
    map<int,vin> mp;
//    mp[0].push_back(1);
    vin pr(n+1,0);
    var2 lr(n+1,{0,0});
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]+a[i];
        mp[pr[i-1]].push_back(i);
        lr[i]=lr[i-1];
        if (a[i]==x){
            lr[i][1]=i;
        }
        if (a[i]>x){
            lr[i][0]=i;
            lr[i][1]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if (a[i]>x) continue;
        int l=lr[i][0];
        int r=lr[i][1];
 //       cout <<i << " " << l << " " << r << "\n";
        int lo=-1;
        int ro=-1;
        int n=mp[pr[i]-s].size();
        if (n==0) continue;
        for(int j=0;j<n;j++){
            int k=mp[pr[i]-s][j];
            if (k>=l+1){
                lo=j;
                break;
            }
        }
        if (lo==-1) continue;
        int ti=n-1;
        int xq= upper_bound(mp[pr[i]-s].begin(), mp[pr[i] - s].end(),r)-mp[pr[i]-s].begin();
        ti=min(xq,n-1);
//        cout << n-1 <<" "<< xq << "\n";
        for(int j=ti;j>=0;j--){
            int k=mp[pr[i]-s][j];
            if (k<=r){
                ro=j;
                break;
            }
        }
 //       cout << lo << " " << ro << "\n";
        if (ro==-1) continue;
        ans+=(ro-lo+1);
/*        for(auto k : mp[pr[i]-s]){
            if (k<=r && k>=l+1 && a[k]<=x) ans++;
            else if (k>r) break;
            //           cout << k << " " << i << "\n";
        }*/
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
    return 0;
}