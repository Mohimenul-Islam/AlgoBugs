#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n ;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int start = 0;
    while(true){
        if(!mp[start])break;
        else start++;
    }
    vector<int > ans(n+1);
    ans[0] = 1 ;
    for(int i = 1; i <= n; i++) {
        int cnt =  0;
        for(int j = start;j>=0; j--) {
            int have_to_stay = j;
            int have_to_be_deleted = mp[j];
            int rest = n - i;
            if(rest>=have_to_stay&& i >= have_to_be_deleted) {
                cnt++;
            }
        }
        ans[i] = cnt;
    }
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}