#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(vector<int>&v,int n, int op)
{   
    int i=1, j=n, ct=0, tot=0;
    set<int>s;
    for(int i=1; i<=op; ++i) s.insert(i);
    while(i<=n and ct<op)
    {    
        if(s.upper_bound(v[i])!=s.begin())
        {   
            s.erase(--s.upper_bound(v[i]));
            ct++;
            tot-=i;
        }
        i++;
    }
    for(int i=1; i<=op; ++i) s.insert(i);
    ct=0;
    while(j>=1 and ct<op)
    {
        if(s.upper_bound(v[j])!=s.begin())
        {   
            s.erase(--s.upper_bound(v[j]));
            ct++;
            tot+=j;
        }
        j--;
    }
    if(j>=i-1) return tot;
    else return 0;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n+1);
        for(int i=1; i<=n; ++i) cin>>v[i];
        int lo=0, hi=n/2, ans=0;
        while(lo<=hi)
        {
            int mid1=lo+(hi-lo)/3,mid2=hi-(hi-lo)/3,val1=func(v,n,mid1),val2=func(v,n,mid2);
            ans=max(ans,max(val1,val2));
            if(val1>=val2) hi=mid2-1;
            else lo=mid1+1;
        }
        cout<<ans<<endl;
    }
}