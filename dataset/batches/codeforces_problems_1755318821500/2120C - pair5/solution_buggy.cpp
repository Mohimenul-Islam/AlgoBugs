#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<vector<int>> solve(int n, int m){
    int root = n;
    ll max_s = ((ll)n*((ll)n+1))/2, min_s = n;
    if(m> max_s || m < min_s)
        return {{-1}};
    vector<vector<int>> ans;
    ll sum = m;
    for(int i=n;i>=1; i--){
        if(i + i-1 < sum){
            sum -= i;
            if(i!=n)
                ans.push_back({n, i});
        }
        else{
            int x = sum - i + 1;
            if(i!=root){
                ans.push_back({x, root});
            }
            else{
                root = x;
            }
            if(x!=1)
                ans.push_back({1, x});
            while(i>1){
                if(i!=x && i!=root){
                    ans.push_back({1,i});
                }
                i--;
            }
        }
    }
    cout<<root<<"\n";
    return ans;
        
}

int main() {
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        ll m ; cin>>m;
        vector<vector<int>> ans = solve(n, m);
        for(vector<int> x: ans){
            for(int y:x)
                cout<<y<<" ";
            cout<<"\n";
        }        

    }
    return 0;
}