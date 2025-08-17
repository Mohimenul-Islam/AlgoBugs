#include <iostream>
#include <vector>
#define ll long long 
using namespace std;


void solve(){
    ll n,m;
    cin>>n>>m;
    if(m<n||m>n*(n+1)/2){
        cout<<-1<<endl;
        return;
    }

    // cout<<n-1<<endl;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    vector<int>order(n);
    int ind=0;
    int val=n;
    int pendingNodes=n;
    int avoid=-1;
    while(m>pendingNodes){
        if(m-pendingNodes>=val){
            order[ind++]=val;
            m-=val;
            pendingNodes--;
            val--;
        }
        else{
            order[ind++]=m-pendingNodes+1;
            avoid=m-pendingNodes+1;
            m=pendingNodes-1;
        }
    }
    cout<<n-1<<endl;
    for(int i=0;i<ind-1;i++){
        cout<<order[i]<<" "<<order[i+1]<<endl;
    }
    // cout<<"ind is "<<ind<<endl;
    if(ind==0){
        for(int i=1;i<n;i++){
            cout<<i<<" "<<i+1<<endl;
        }
        return;
    }
    int last=order[ind-1];
    for(int i=1;i<=val;i++){
        if(i==avoid){
            continue;
        }
        cout<<last<<" "<<i<<endl;
        last=i;
    }
    return;
}
int main(){
    ll test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}