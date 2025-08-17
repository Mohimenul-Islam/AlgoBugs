#include<bits/stdc++.h>
#include<cmath>
#include<cstring>
#include<numeric>
#include <algorithm>
using namespace std;
#define orderedset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define I_love_nbs() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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

#define mod 100000007
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define sqr(a) ((a)*(a))
typedef vector<int>vi;
typedef vector<ll>vll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<pair<int,int>>vpii;
typedef vector<pair<ll,ll>>vpll;

const int mx=5e3+5;
const double mx1=-100000000.00000;
const int inf=1e9;
vll adj[mx];


ll mul(ll a,ll b)
{
    return ((((a%mod)+mod)%mod)*(((b%mod)+mod)%mod))%mod;
}

ll add(ll a,ll b)
{
    return ((((a%mod)+mod)%mod)+(((b%mod)+mod)%mod))%mod;
}

void solve(int t1)
{
ll n,m;
cin>>n>>m;
ll f=(1ll*n*(n+1))/2;
set<ll>st;
for(int i=1;i<=n;i++)st.insert(i);
if(m>f ||n>m)
{
    cout<<-1<<endl;
}
else
{vll v(n+1,1ll);
    ll h=n;
    ll dif=m-n;
    h--;
    for(int i=0;i<n;i++)
    {
       if(h<=dif)
       {
           dif-=h;
           v[i]+=h;
       }
       else
       {
           v[i]+=dif;
           dif=0;
           break;
       }
    }
    bool vis[n+1];
    mem(vis,0);
    vll v1;
    for(int i=0;i<n;i++)
    {
        if(vis[v[i]]==0)
        {
            v1.pb(v[i]);
            st.erase(v[i]);
            vis[v[i]]=1;
        }
        else
        {ll it;
        it=*(st.rbegin());
         v1.pb(it);
         st.erase(it);
        }
    }
    cout<<v1[0]<<endl;
    for(int i=0;i<v1.size()-1;i++)
    {
        cout<<v1[i]<<" "<<v1[i+1]<<endl;
    }
}
}


 int main()
 {
     I_love_nbs();
    int t=1;
cin>>t;
for(int i=1;i<=t;i++)
     {
       solve(i);
     }
  }
