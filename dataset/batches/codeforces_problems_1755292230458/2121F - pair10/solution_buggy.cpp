#include <bits/stdc++.h>
using namespace std;
#define int long long int
// #define ll long long int 
#define ld long double
#define endl '\n'
#define pii pair<int,int>
#define vi vector<int>
#define vp vector<pii>
#define all(a) a.begin(), a.end()
#define fr1(i,n) for(int i=0;i<n;++i)
#define fr2(i,n) for(int i=n-1;i>=0;i--)


void solve(){

    int n, s, x; cin>>n>>s>>x;
    vi pr(n), xps, xgps;
    fr1(i, n){
        cin>>pr[i]; 
        if(pr[i] == x) xps.push_back(i); 
        if(pr[i] > x) xgps.push_back(i); 
        if(i) pr[i] += pr[i-1]; 
    } 
    xgps.push_back(n); 

    map<int, vi> mp; 
    fr1(i, n){
        mp[pr[i]].push_back(i); 
    }

    int ans = 0, ps = 0, gps = 0; 
    fr1(i, n){
        if(ps == xps.size()){
            break;
        }

        int rsm = s;
        if(i) rsm += pr[i-1];
        if(mp.find(rsm) != mp.end()){
            vi rq = mp[rsm]; 
            auto it1 = lower_bound(rq.begin(), rq.end(), xps[ps]);
            auto it2 = lower_bound(rq.begin(), rq.end(), xgps[gps]);
            ans += max(0ll, (int)(it2-it1)); 
        }

        if(i == xps[ps]) ps++;
        if(i == xgps[gps]) gps++; 
    }
    cout<<ans<<endl;


}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif

    clock_t z = clock();
    int test = 1 ;
    cin>>test;
    while(test--) solve();

    cerr<<"Run Time : "<< ((double)(clock() - z)/CLOCKS_PER_SEC);
    return 0;
}