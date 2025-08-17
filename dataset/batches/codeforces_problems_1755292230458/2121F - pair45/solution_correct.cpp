#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>

ll ans=0;
ll n,s,x;

void dfs(vector<ll> &tmp){
    // for(auto &e:tmp)
    //     cout<<e<<" ";
    // cout<<endl;
    
    ll len=(ll)tmp.size();
    vector<ll> pref(len);

    set<ll> st;
    for(ll i=0;i<len;i++)
        if(tmp[i]==x)
            st.insert(i);

    for(ll i=1;i<len;i++)
        pref[i]=pref[i-1]+tmp[i];

    map<ll,vector<ll>> mp;
    for(ll i=0;i<len;i++){
        mp[pref[i]].push_back(i);
    }

    for(ll i=0;i<len;i++){
        ll tar=pref[i]+s;
        auto it=st.upper_bound(i);
        if(it==st.end())
            break;
        if(mp.count(tar)==0)
            continue;
        ll pos=lower_bound(mp[tar].begin(),mp[tar].end(),*it)-mp[tar].begin();
        ll cnt=(ll)mp[tar].size()-pos;
        // cout<<*it<<" "<<pos<<" "<<mp[tar].size()<<endl;
        ans+=cnt;
    }
}

void solve(){
    ans=0;
    cin>>n>>s>>x;

    vector<ll> vt(n);
    for(auto &e:vt)
        cin>>e;

    ll l=0,r=0;
    for(;l<n;){
        r=l;
        ll idx=0;
        ll maks=vt[r];
        while(r+1<n && vt[r+1]<=x && maks<=x){
            r++;
            maks=max(maks,vt[r]);
        }
        if(maks==x){
            vector<ll> tmp={0};
            for(ll i=l;i<=r;i++)
                tmp.push_back(vt[i]);
            dfs(tmp);
        }
        l=r+1;
    }

    cout<<ans<<endl;
}


int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(NULL);cin.tie(0);

    ll t=1;
    cin>>t;

        
    while(t--)
        solve();

}
