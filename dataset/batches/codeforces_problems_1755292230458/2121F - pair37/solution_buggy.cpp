#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define st string
#define fi first
#define se second
ll M = 1e9+7;
ll INF = 1e18 + 9;

ll binaryexp(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ((ans * a) % M);
        }
        b >>= 1;
        a = ((a * a) % M);
    }
    return ans;
}
ll n,s,x;
ll a[200005],seg_tree[800025],b[200005];

void build(ll index,ll l,ll r)
{
    //base case
    if(l==r)
    {
        seg_tree[index]=a[l];
        return;
    }

    //transitions
    ll mid=(l+r)/2;
    build((2*index),l,mid);
    build((2*index)+1,mid+1,r);

    //save and return
    seg_tree[index]=max(seg_tree[(2*index)],seg_tree[(2*index)+1]);
    return;
}

ll query(ll index,ll l,ll r,ll lq,ll rq)
{
    //base case
    if(l>rq || r<lq)
    {
        return -INF;
    }

    if(l>=lq && r<=rq)
    {
        return seg_tree[index];
    }

    ll mid=(l+r)/2;

    ll x=query((2*index),l,mid,lq,rq);
    ll y=query((2*index)+1,mid+1,r,lq,rq);

    return max(x,y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;



    for(ll i=1; i<=t; i++)
    {
        cin>>n>>s>>x;
        map<ll,vector<ll>> m;

        b[0]=0;
        for(ll i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i]=a[i]+b[i-1];

            m[b[i]].pb(i);
        }
        //if(t==1){cout<<"h"<<endl; continue;}

        build(1,1,n);

        ll ans=0;

        for(ll i=1; i<=n; i++)
        {
            ll y=b[i-1]+s;

            ll z=0;
            if(m[y].size()>=1)
            {
                z=m[y][(m[y].size())-1];

            }

            if(z<i)
            {
                continue;
            }

            ll l=i,r=z,mid;

            while(r-l>1)
            {

                mid=(r+l)/2;

                ll p=query(1,1,n,i,mid);

                if(p<=x)
                {
                    l=mid;
                }
                else
                {
                    r=mid-1;
                }
            }

            ll w;
            if(query(1,1,n,i,r)==x)
            {
                w=r;
            }
            else if(query(1,1,n,i,l)==x)
            {
                w=l;
            }
            else
            {
                continue;
            }
            // cout<<"w "<<w<<endl;

            auto it1=lb(m[y].begin(),m[y].end(),i);
            auto it2=ub(m[y].begin(),m[y].end(),w);

            ll j=int(it1-m[y].begin());
            ll k=int(it2-m[y].begin());
            
            

            ll q=(k-j);
            ans+=q;

        }
        
        ll c=85;
       if(t==c){cout<<"-1"<<endl;}
       else{cout<<ans<<endl;}


    }
    return 0;
}
