#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    ll n,m;
    cin>>n>>m;
    if(m > (n * (n+1)/2) || m < n){
        cout<<-1<<endl;
        return;
    }


    vector<ll> visited(n,0);
    ll sum=n;
    for(int i=n-1;i>=0;i--){
        if(i+ sum <= m){
            sum += i;
            visited[i]=1;
        }
    }
    vector<ll> ans;
    for(int i=visited.size()-1;i>=0;i--){
        if(visited[i]==1){
            ans.push_back(i);
        }
    }
    for(int i=1;i<visited.size();i++){
        if(visited[i]!=1){
            ans.push_back(i);
        }
    }
    cout<<ans[0]+1<<endl;
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]+1<<" "<<ans[i+1]+1<<endl;
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}