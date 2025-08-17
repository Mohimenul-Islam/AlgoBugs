#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (;t>0;t--){
      long long n,s,x;
      cin >> n >> s >> x;
      long long a[n];
      for (int i=0; i<n; i++) {
        cin >> a[i];
      }
      map <int,vector<int> > prefix;
      prefix[0].push_back(-1);
      int last_x = -2;
      int last_greater = -2;
      long long ans = 0;
      long long sum = 0;
      for (int i=0; i<n; i++) {
        sum+=a[i];
        if (a[i]==x) {
          last_x = i;
        }
        if (a[i]>x) {
          last_greater = i;
        }
        if (prefix.find(sum-s)!=prefix.end()) {
          auto upper_pos = lower_bound(prefix[sum-s].begin(),prefix[sum-s].end(),last_x);
          auto lower_pos = lower_bound(prefix[sum-s].begin(),prefix[sum-s].end(),last_greater);
          int inc = upper_pos-lower_pos;
          ans+=max(0,inc);
        }
        prefix[sum].push_back(i);
      }
      cout << ans << "\n";
    }
}