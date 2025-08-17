#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>
#include <iomanip>  
#include <climits>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#define MOD 1000000007
using namespace std;
#define int long long


 
void solve(){
    int n, s, x; 
    cin >> n >> s >> x; 
    vector <int> v(n); 
    vector <int> h; 
    for(int i = 0; i < n; i++) cin >> v[i]; 
    vector <int> pref(n+1); 
    for(int i = 0; i < n; i++) pref[i+1] = pref[i] + v[i]; 

    // for(int i = 0; i <= n; i++) cout << pref[i] << " "; 
    // cout << endl;

    int ans = 0;
    map <int, int> q;  
    int ind = -1; 
    for(int i = 1; i <= n; i++){
        if(v[i-1]>x){
            ind = i; 
            q.clear();
            continue; 
        }
        if(v[i-1]==x){
            if(ind==-1){
                q[0]++; 
                ind = 1;  
            }
            while(ind < i){
                q[pref[ind]]++; 
                ind++; 
            }
        }
        if(q.find(pref[i]-s)!=q.end()) ans+=q[pref[i]-s]; 
        // cout << ans << endl;
    }

    cout << ans << endl; 

} 
 

#undef int

int main(){
    
    int t;
    cin >> t;
    while(t){
        solve(); 
        t--; 
    }
        
    return 0; 
}