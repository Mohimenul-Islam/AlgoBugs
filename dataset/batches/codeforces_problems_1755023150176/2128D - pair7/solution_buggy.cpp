#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
//#define int long long
using namespace std;




/*int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int nn=n;
    vector <int>v,v2;

    int i=2;
    while(n!=1)
    {

        while(n%i==0)
            {
            n=n/i;
            v.push_back(i);
        }
        i++;

    }
    int c=1;
    int a[1005];
    memset(a,0,sizeof(a));
        int m=0;
        int index=0;
        int t=0;
        for(auto u : v){
            if(u==t){
                a[index]++;
            }
            else{
                index++;
                v2.push_back(u);
                c=c*u;
            }
            t=u;

        }
        for(int i=0;i<1003;i++){
            m=max(m,a[i]+1);
        }
        bool b1=true,b2=false;

        for(int i=1;i<=index;i++){
            //cout<<a[i]<<endl;
            if(a[1]!=a[i]){
                b1=false;
            }
        }
        for(int i=1;i<30;i++){
            if(m==pow(2,i)){
                b2=true;
            }
        }



    if(m==1){
        cout<<nn<<" "<<0<<endl;
    }
    else if(b1&&b2)
    {
        cout<<c<<" "<<ceil(log2(m))<<endl;
    }
    else{
        cout<<c<<" "<<ceil(log2(m))+1<<endl;
    }



}*//*
int main(){
int q;
cin>>q;
while(q--){
    int n;
    cin>>n;
    if(n==2){
        cout<<3<<endl;
        continue;
    }
    int m=ceil(log2(n));
    if(n!=pow(2,m)-1){
    cout<<(int)pow(2,m)-1<<endl;
    }

    else{
            int ma=1;
        for(int i=2;i*i<n;i++){
            if(n%i==0){
                ma=max(n/i,ma);
            }
        }
        cout<<ma<<endl;
    }

}


}
*/
/*
int main()
{
int t;
cin>>t;
while(t--){
        int n;
    cin>>n;
    int a[200005];
    for(int i=0;i<n;i++){
        if(i%2==0){
            a[i]=-1;
        }
        else{

            a[i]=3;
        }
    }
    if(n%2==0){
        a[n-1]=2;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}




}*/
int main(){
int t;
cin>>t;
while(t--){

    int a[500005],n,dp[500005];
cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    dp[0]=0;
    int l=0,k=0;
    for(int r=2;r<=n;r++){
      if(a[r]<a[r-1]){
            dp[r]=dp[r-1]+r;
        }
        else{
            dp[r]=dp[r-1]+1;
        }
          //  cout<<r<<" "<<l<<k

    }
    int ans=0;
        for(int i=1;i<=n;i++){
            ans+=dp[i];

        }
        cout<<ans<<endl;

}
}
