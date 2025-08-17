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

    int ans = 0;
    map <int, int> q;  
    map <int, int> temp;
    temp[0]=1;
    int sum = 0; 
    for(int i = 0; i < n; i++){
        if(v[i]>x){
            sum = 0; 
            map <int, int> q;  
            map <int, int> temp;
            temp[0] = 1; 
            continue; 
        }
        if(v[i]==x){
            q = temp; 
        }
        sum += v[i]; 
        temp[sum]++; 
        if(q.find(sum-s)!=q.end()) ans+=q[sum-s]; 
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