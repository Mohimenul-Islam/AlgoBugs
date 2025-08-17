#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define s191213m ios_base:: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long
#define lld long long double
#define hae cout<<"YES\n"
#define nah cout<<"NO\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define f(i,n) for(i=0;i<n;i++)
#define vin(a) for(i=0;i<n;i++) { cin>>j; a.pb(j); }
#define mapp(m) map<ll,ll>m
#define endl '\n'
#define mod 1e9+7
#define mod1 1e9+7
#define mod2 998244353
#define ofk order_of_key
#define fbo find_by_order
#define l_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define g_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pq_min priority_queue<ll, vector<ll>, greater<ll>>

ll mod_add(ll a,ll b,ll m)
{
    return (a%m+b%m)%m;
}
//
int mod_sub(int a,int b,int m)
{
    return (a%m-b%m+m)%m;
}
//
ll mod_mul(ll a,ll b,ll m)
{
    return (a%m*b%m)%m;
}
//
ll mod_expo(ll a,ll b,ll m)
{
    if(b==0) return 1;
    ll res=mod_expo(a,b/2,m);
    res=mod_mul(res,res,m);
    if(b%2==1) res=mod_mul(res,a,m);
    return res;
}
//
ll mod_inv(ll a,ll m)
{
    return mod_expo(a,m-2,m);
}

ll mod_div(ll a,ll b,ll m)
{
    return mod_mul(a,mod_inv(b,m),m);
}

vector<ll>ans;
void dfs(ll n,ll &z,vector<map<ll,ll>>&tree,vector<ll>&a,vector<ll>&visit)
{
    if(z>0)
    {
        return;
    }
    visit[n]++;
    for(auto t:tree[n])
    {
        ll p=t.second;
        if(z>0)
            return;
        if(p!=max(a[n],a[t.first]))
        {
            z++;
            return;
        }
        if(visit[t.first]==0)
        {
            dfs(t.first,z,tree,a,visit);
        }
    }

}
long long binpow(long long a, long long b, long long m)
{
    long long result = 1;
    a = a % m;  // In case a is larger than mod

    while (b > 0)
    {
        // If b is odd, multiply result by a
        if (b % 2 == 1)
        {
            result = (result * a) % m;
        }

        // Square the base and reduce the exponent by half
        a = (a * a) % m;
        b /= 2;  // Integer division by 2
    }

    return result;
}
ll digitSum(ll n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;  // add last digit
        n /= 10;        // remove last digit
    }
    return sum;
}

bool cmp(pair<ll,pair<ll,ll>>&p,pair<ll,pair<ll,ll>>&p1)
{
    if(p.first<p1.first)
        return 1;
    else if(p.first==p1.first)
        if(p.second.first<p1.second.first)
            return 1;
    return 0;
}
bool cmp1(pair<ll,ll>&p,pair<ll,ll>&p1)
{
    if(p.first<p1.first)
        return 1;
    else if(p.first==p1.first)
        if(p.second>p1.second)
            return 1;
    return 0;
}
bool cmp2(pair<ll,pair<ll,ll>>&p,pair<ll,pair<ll,ll>>&p1)
{
    return p.second.first>p1.second.first;
}
vector<ll>prime= {2,3,5,7};


void right_nearest_greater(vector<ll> &a,vector<ll> &r)
{
    stack<pair<ll,ll>>s;
    ll i,n=a.size();
    for(i=n-1; i>=0; i--)
    {
        if(s.size()==0)
        {
            r[i]=n;
            s.push({a[i],i});
        }
        else
        {
            while( s.size()>0)
            {
                if(s.top().first>a[i])
                    break;
                s.pop();
            }
            if(s.size()==0)
                r[i]=n;
            else
                r[i]=s.top().second;
            s.push({a[i],i});
        }
    }
}
vector<ll>fact(300005,1);
void factorial()
{
    ll i;
    for(i=1; i<300005; i++)
    {
        fact[i]=mod_mul(fact[i-1],i,mod);
    }
}
ll dfs(ll n,ll tt,ll p,ll &c,vector<vector<ll>>&tree,vector<ll>&visit)
{
    visit[n]++;
    if(c>0)
        return 0;
    //cout<<n<<" "<<p<<endl;
    if(tree[n].size()==1)
        return 1;
    vector<ll>a;
    ll y=0,y1=0;
    if(p!=0)
        y=fact[tree[n].size()-2];
    ll c2=0;
    for(auto &t:tree[n])
    {
        if(visit[t]!=0)
        {
            if(t!=p)
            {
                c++;
                return 0;
            }
        }
        else
        {
            if(tree[t].size()>1)
                y1++;
            //cout<<n<<" =>"<<y<<" "<<x<<"\n";
            ll z=dfs(t,tt,n,c,tree,visit);
            if(p!=0)
            {
                y=mod_mul(y,z,mod);
            }
            else if(tree[t].size()>1)
                a.pb(z);
            //cout<<t<<" =>"<<z<<" "<<y<<endl;
        }
    }
    ll cc=2;
    if(p!=0)
        cc=1;
    if(y1>cc)
        c++;
    if(p!=0)
    {
        if(y1==0)
            y=fact[tree[n].size()-1];
        //cout<<n<<" => "<<" "<<y<<endl;
        return y;
    }
    //cout<<a.size()<<endl;
    if(a.size()==0)
        y=fact[tree[n].size()];
    else if(a.size()==1)
        y=mod_mul(2,mod_mul(fact[tree[n].size()-1],a[0],mod),mod);
    else
        y=mod_mul(2,mod_mul(fact[tree[n].size()-2],mod_mul(a[0],a[1],mod),mod),mod);
    //cout<<n<<" => "<<" "<<y<<endl;
    return y;

}
ll t1=1;

void solve()
{
    //cout<<endl;
    ll n,i,j,k,r=0,c=0,c1=0,c2=0,l=1e18,m;
    vector<string> s;
    string s1;
    ll st=1e18,en=0;
    cin>>n>>m;
    s1=(to_string(n));
    s.pb(s1);
    s.pb(",");
    s1=(to_string(m));
    s.pb(s1);
    //cout<<s<<endl;
    vector<vector<ll>>tree(n+1);
    vector<ll>visit(n+1,0);
    for(i=1; i<=m; i++)
    {
        ll x,y;
        cin>>x>>y;
        s1=to_string(x);
        s.pb("(");
        s.pb(s1);
        s1=to_string(y);
        s.pb(",");
        s.pb(s1);
        s.pb(")");
        tree[x].pb(y);
        tree[y].pb(x);
    }
//    if(t1==45)
//    {
//        for(i=0; i<s.size(); i++)
//            cout<<s[i];
//        cout<<endl;
//    }

    if(n==2)
    {
        cout<<2<<endl;
        return;
    }
    for(i=1; i<=n; i++)
    {
        if(tree[i].size()>1)
        {
            c++;
            c2=0;
            ll x=dfs(i,i,0,c2,tree,visit);
            if(c2>0)
            {
                cout<<0<<endl;
                return;
            }
            x=mod_mul(x,2,mod);
            cout<<x<<endl;
            return;
        }
    }
    cout<<0<<endl;















}


int main()
{
    //s191213m
    //ans.pb(0);
    //cout<<"{1,1}"<<endl;
    //cout<<1<<endl;
    ll t,s=0;
//    fib.pb(1);
//    fib.pb(1);
//    for(ll i=2; i<=45; i++)
//    {
//        fib.pb(fib[i-1]+fib[i-2]);
//    }
    //cout<<fib[45]<<endl;

    //is_prime();
    //randomMod();
    //pre();
    factorial();
    t=1;
    cin>>t;
    //t3=t;
    while(t--)
    {
        solve();
        //cout<<endl;
        t1++;
    }


}

