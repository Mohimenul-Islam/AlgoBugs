#include<bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define e '\n'
#define pb push_back
#define yes "YES"
#define no "NO"
#define F first
#define S second
//#define srt(a) sort(a,a+n)
//#define srt(v) s5ort(v.begin(),v.end())
//#define srt(u) sort(u.begin(),u.end())
#define loop  for(i=1;i<=n;i++)
const int mod=1e9+7;
const int MOD=998244353;
const int lx=1e5+25;
//pair<ll,ll>p[222222];
//map<ll,ll>mp;
//typedef pair<int, int> pi;
//sort(p,p+n,greater<pair<ll,ll>>());-sort vector pair decending order
//priority_queue<pi,vector<pi>,greater<pi>>pq;
//priority_queue<int,vector<int>,greater<int>>pq;-minheap
//priority_queue<pair<int,int>>pq;
//s.erase(position,length)


void solve(){
    ll i=0,j=0,k,c1=0,c2=0,cnt=0,mx=-1e18+7,mn=1e18+7;
    ll n,m,ans=0,sum=0,ans1=0,ans2=0;
    ll s, x;
    cin>>n>>s>>x;

    ll a[n+1], pre[n+1]={0};
    for(i=1; i<=n; i++){
        cin>>a[i];
        sum += a[i];
        pre[i] = sum;
    }
    map<ll, ll>mp;
    ll left = 1;
    for(i=1; i<=n; i++){
        if(a[i] > x)
            mp.clear(), left = i+1;
        else if(a[i] == x){
            while(left <= i){
                mp[pre[left - 1]]++;
                left++;
            }
        }
        ans += mp[pre[i] - s];
    }

    cout<<ans<<e;


}



int main(){
    fast()
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}

//        **Number Theory***

//        sort(a+1,a+n+1);
//        long long gcd=a[1];
//        for(int i=2;i<=n;i++){
//             gcd = __gcd(a[i],gcd);
//        }
//         cout<<gcd<<endl;

//        long long s[10];
//        for(i=1;i<10;i++)
//            s[i]=i;
//        s[1]=2;
//        for(i=2;i<10;i++){
//            q=s[i]*s[i-1];
//            long long gcd = __gcd(s[i],s[i-1]);
//            s[i]=q/gcd;//   -LCM
//        }
//        for(i=1;i<10;i++)
//            cout<<s[i]<<" ";
//        *Linear Diophantine Equations
//        1.ax+by=c
//        there will be a solution if gcd(a,b) can divide c

//        convert string to int and int to string
//        string t;
//        cin>>n;
//        p=stoi(t);
//        std:: string s = std::to_string(n);
//        cout<<s;
//        build all permutation of a string
//        string s="1234";
//        do {
//            std::cout<<s<<std::endl;
//        } while (std::next_permutation(s.begin(),s.end()));


//    Harmonic series-nlogn
//    for(i=1;i<=n;i++){
//        for(j=i;j<=n;j+=i)
//            operation.....
//    }

