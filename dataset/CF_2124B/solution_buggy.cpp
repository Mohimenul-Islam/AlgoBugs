#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int minsum=0,minsum2=0;
        for(int i=0,premin=n+1;i<n;i++){
            cin>>a[i];
            premin = min(premin,a[i]);
            minsum += premin;
        }
        for(int i=0,premin=n+1,op=0;i<n;i++){
            premin = min(premin,a[i]);
            minsum2 += premin;
            if(i>0 && i+1<=n-1 && a[i]>=premin && op==0){
                a[i]=a[i]+a[i+1];
                a[i+1]=0;
                op++;
            }
        }
        cout<<min(minsum,minsum2)<<endl;
    }
}