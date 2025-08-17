#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define vec vector 
#define endl '\n' 
#define _ios ios::sync_with_stdio(false) ,cin.tie(nullptr) , cout.tie(nullptr) 
template<class T,class S> 
T cmin(T a, S b){T c = b ; return min(a,c);} 
template<class T , class S > 
T cmax(T a,S b) { T c = b ; return max(a,c);} 

void MinakamiYuki(){
    ll n ; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll yuki =0;
    for(ll i=1;i<=n;i++){
        yuki+= i*(n-i+1);
    }
    for(ll i=0;i<n-1;i++){
        if(a[i] <a[i+1]) yuki -= (i+1)*(n-i-1);
    }
    cout<<yuki<<endl;
}

int main(){
    _ios; 
    int _t; cin>>_t;
    while(_t--) MinakamiYuki();
}