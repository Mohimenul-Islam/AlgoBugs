#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define irep rep(i,0,n)
#define int long long
#define pii pair<int,int>
#define si set<int>
#define in(a) int a;cin>>a;
#define nod(i) cout<<fixed<<setprecision(i)
#define take(a,n) int a[n]; for(int j=0;j<n;j++) cin>>a[j];
#define ssin string s; cin>>s;
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


void solve()
{
    in(n)in(k)
    take(d,n)
    multiset<int> s;
    irep{s.insert(d[i]);}
    int ans=0;
    while(s.size()>0){
        auto it=s.begin();
        int sm=(*it);
        s.erase(it);
        ans++;
        if(sm>=k){continue;}
        if(s.size()==0){break;}
        auto it1=s.end();
        it1--;
        s.erase(it1);
        if(s.size()==0){break;}
        int x=k-(sm);
        auto it2=s.lower_bound(x);
        if(it2==s.begin()){continue;}
        it2--;
        s.erase(it2);
        // cout<<s.size()<<" ";
    }
    cout<<ans-1<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}