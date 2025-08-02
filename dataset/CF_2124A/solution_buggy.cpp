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

bool isDerangement(const vector<int>& b) {
    int m = b.size();
    vector<int> c = b;
    sort(c.begin(), c.end());
    for (int i = 0; i < m; ++i) {
        if (b[i] == c[i]) return false;
    }
    return true;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // Try full array
    if (isDerangement(a)) {
        cout << "YES\n" << n << "\n";
        for (int v : a) cout << v << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        vector<int> b;
        b.reserve(n-1);
        for (int j = 0; j < n; ++j) if (j != i) b.push_back(a[j]);
        if (!b.empty() && isDerangement(b)) {
            cout << "YES\n" << b.size() << "\n";
            for (int v : b) cout << v << " ";
            cout << "\n";
            return;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            vector<int> b;
            b.reserve(n-2);
            for (int k = 0; k < n; ++k) if (k!=i && k!=j) b.push_back(a[k]);
            if (!b.empty() && isDerangement(b)) {
                cout << "YES\n" << b.size() << "\n";
                for (int v : b) cout << v << " ";
                cout << "\n";
                return;
            }
        }
    }

    cout << "NO\n";
}
