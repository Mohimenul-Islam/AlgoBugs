// A. Deranged Deletions
// By souravbiswas35
#include <bits/stdc++.h>
using namespace std;

const int MX = 200000 + 5;
void Solve();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) Solve();
    return 0;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 1; i < n; ++i) {
        if (a[i-1] > a[i]) {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << a[i-1] << " " << a[i] << "\n";
            return;
        }
    }

    cout << "NO\n";
}
