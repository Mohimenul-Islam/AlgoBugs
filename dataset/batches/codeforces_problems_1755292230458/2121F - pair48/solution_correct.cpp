#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        long long s, x;
        cin>>n>>s>>x;
        int a[n]; 
        long long sum[n+1];
        sum[0] = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            sum[i+1] = sum[i] + a[i];
        }
        // for(int i =0;i<=n;i++) cout<<sum[i]<<" ";
        // cout<<"\n";
        map<int,int> pre;
        long long answer = 0;
        for(int i = 0;i<n;i++){
            if(a[i]>x){
                pre.clear();
            }else if(a[i] == x){ 
                int index = i;
                pre[sum[index]]++;
                index--;
                while(index>=0 && a[index]<x){
                    pre[sum[index]]++;
                    index--;
                }  
                // cout<<pre.size()<<"\n";
            }
            answer += pre[sum[i+1]-s];
        }
        cout<<answer<<'\n';
    }
}