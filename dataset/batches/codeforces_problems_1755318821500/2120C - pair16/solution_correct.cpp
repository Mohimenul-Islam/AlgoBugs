#include<bits/stdc++.h>
#include<cmath>
#include<cstring>
#include<numeric>
#include <algorithm>
using namespace std;
#define orderedset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define tawfiq123() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define endl '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define sqr(a) ((a)*(a))

typedef vector<int>vi;
typedef vector<ll>vll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<pair<int,int>>vpii;
typedef vector<pair<ll,ll>>vpll;

const ll p=1e6+123;
const int mx=998244353;
const ll inf=9000000000000000000;
bool vis[p];



void solve()
{
    ll n,m;
    cin>>n>>m;
    ll k=(n*(n+1))/2;
    if(n>m ||k<m)
    {
        cout<<-1<<endl;
        return;
    }
    mem(vis,0);
    vll v;
    int c=0;
    for(int i=n;i>=1;i--)
    {
        if(m-i>=(n-1-c))
        {
            v.pb(i);
            m-=i;
            vis[i]=1;
            c++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])v.pb(i);
    }
    cout<<v[0]<<endl;
    for(int i=0;i<v.size()-1;i++)cout<<v[i]<<" "<<v[i+1]<<endl;

}


 int main()
 {
     tawfiq123();
    int t=1;
     cin>>t;

 while(t--)
     {
       solve();
     }
  }
