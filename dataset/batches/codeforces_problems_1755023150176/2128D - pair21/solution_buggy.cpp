#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<ll>
#define l_b lower_bound
#define u_b upper_bound
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define re return
int mod=1e9+7;
void input(vector<ll>& arr,int n)
{
    for(int i=0;i<n;i++)
    {
        ll j;
        cin>>j;
        arr.push_back(j);
    }
}
void print(vi& arr,int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i];
    cout<<endl;
}
void checkprime(ll n,vi& arr)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            arr.push_back(i);
        if((i*i)!=n)
            arr.push_back(n/i);
    }
}
ll gcd(ll  a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void findpsum(vi& arr,vi& psum,ll n)
{
    psum[0]=0;
    for(int i=0;i<n;i++)
        psum[i+1]=psum[i]+arr[i];
}
int findGCD(vector<ll> &arr) {
    ll res = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        res = gcd(arr[i], res);
        if (res == 1)
            return 1;
    }
    return res;
}
bool possible(vi& arr,ll n,ll k,ll start)
{
    bool res=true;
    if(start!=(k-1))
        res=false;
    for(int i=start;(i+k)<n;i+=k)
    {
        if(arr[i]==arr[i+k])
            continue;
        if(res)
            res=false;
        else
            re false;
    }
    re true;
}
ll findk(ll d,ll i)
{
    ll k=1;
    while(1)
    {
        d=pow(d,k-1)+d;
        if(d%i==0)
            return k;
        k++;
    }
}
ll findfact(ll n)
{
    ll fact=1;
    for(ll i=2;i<=n;i++)
        fact*=i;
    return fact;
}
ll findk(ll n)
{
    ll k=0;
    while((1<<k)<n)
    {
        k++;
    }
    return k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vi v;
        input(v,n);
        vector<ll> dp(n,0);
        dp[0] = 1;
        for(int i = 1;i<n;i++)
        {
            if(v[i] < v[i-1])
            dp[i] = dp[i-1] + (i+1);
            else dp[i] = dp[i-1] +1;
        }
        cout << (ll)accumulate(dp.begin(),dp.end(),0) <<endl;
    }
}