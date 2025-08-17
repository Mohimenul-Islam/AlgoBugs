#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    if(m<n || m>(n*(n+1)/2)){
        cout<<-1<<endl;
        return;
    }
    vector<int> arr(n+1);
    // arr[0]=n-1;
    for(int i=1;i<=n;i++){
        int temp=i;
        arr[i]=temp;
    }
    int k=(n*(n+1)/2)-m;
    for(int i=n;i>=1;i--){
        if(k==0) break;
        if(k>=(i-1)){
            arr[i]=1;
            k-=(i-1);
        }
        else{
            arr[i]=i-(k);
            k=0;
        }
    }
    int root=0;
    for(int i=1;i<=n;i++){
        if(i==arr[i]) root=i;
    }
    cout<<root<<endl;
    for(int i=1;i<=n;i++){
        if(arr[i]==i and i!=root){
            cout<<root<<" "<<i<<endl;
        }
        else if(arr[i]!=i){
            cout<<i<<"  "<<arr[i]<<endl;
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}