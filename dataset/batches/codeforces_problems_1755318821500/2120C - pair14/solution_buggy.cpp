#include <bits/stdc++.h>

#define print(arr)                                                             \
  for (auto a : arr) {                                                         \
    cout << a << " ";                                                          \
  }                                                                            \
  cout << "\n";

#define loop(i, a, n) for (int i = a; i < n; i++)
#define input(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define int long long
#define ll long long
#define pii pair<int, int>
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  if (m > (n * (n + 1)) / 2 || m < n) {
    cout << "-1\n";
    return;
  }

  int rem = m - (n - 1);
  int l = n;
  vi out;
  vi used(n + 5, 0);
  while (rem) {

    out.push_back(min(rem, l));
    used[min(rem, l)] = 1;
    rem -= min(rem, l);
    if (min(rem, l) == l) {
      l--;
    }
  }
  if (used[1] == 0) {
    out.push_back(1);
  }
  for (int i = l; i > 1; i--) {
    if (used[i] == 0) {
      out.push_back(i);
    }
  }
  
  cout << out[0] << "\n";
  
  for(int i = 0; i < n -1; i ++){
    cout << out[i] << " " << out[i+1]<< "\n";
  }

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}