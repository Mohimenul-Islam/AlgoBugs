#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);
const int N=1e6+10;
int tree[N];
void built(int n,int a[]){
    for(int i=0;i<n;i++) tree[i+n] = a[i];
    for(int i=n-1;i>=1;i--) tree[i] = max(tree[2*i] , tree[2*i+1]);
}
int maxx(int a, int b,int n) {
    a += n; b += n;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s = max(s,tree[a++]);
        if (b%2 == 0) s = max(s,tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}
int main()
{
    fast
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n; ll s; int x; cin>>s>>x; int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        built(n,a);
        vector<pair<int,pair<int,int>>> ans;
        for(int i=0;i<n;i++){
            if(a[i] == x){
            int loo = i; int hii = i;
            int lo = i; int hi = n-1;
            while(hi-lo>1){
                int mid = (lo+hi)/2;
                if(maxx(i,mid,n) == x){
                    lo = mid;
                }
                else{
                    hi = mid;
                }
            }
            if(maxx(i,hi,n) == x){
                hii = hi;
            }
            else{
                hii = lo;
            }
            lo = 0; hi = i;
            while(hi-lo>1){
                int mid = (lo+hi)/2;
                if(maxx(mid,i,n) == x){
                    hi = mid;
                }
                else{
                    lo = mid;
                }
            }
            // cout<<lo<<" "<<maxx(lo,i,n)<<endl;
            if(maxx(lo,i,n) == x){
                loo = lo;
            }
            else{
                loo = hi;
            }
            ans.push_back({i,{loo,hii}});
        }   

        }
        map<pair<int,int>,int> mp; ll ans1=0;
        for(int i=0;i<ans.size();i++){  
            // cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
            int l = ans[i].second.first; int r = ans[i].second.second; int ind = ans[i].first;
            if(mp[{l,r}] == 0){
                map<ll,ll> mp2;
                ll sum = 0; 
                for(int j=ind;j<=r;j++){
                    // if(a[j] == x) break;
                    sum+=a[j];
                    if(sum == s) ans1++;
                    mp2[sum-x] ++;
                }
                // cout<<ans1<<" ";
                sum = x;
                mp2[0] = 1;
                for(int j = ind-1;j>=l;j--){
                    if(a[j] == x) break;
                    sum+=a[j];
                    int x = s - sum;
                    ans1 += (mp2[x]);  
                }   
            }
            // cout<<ans1<<" ";
            // mp[{l,r}]++;
        }
        cout<<ans1<<endl;
    }
}