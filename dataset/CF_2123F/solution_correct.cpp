#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;
#define ll long long

vector<int> all_prime(int n) {
    bool a[n + 1];
    fill(a, a + n + 1, true);
    int ptn = 2;
    while (ptn < n + 1) {
        if (a[ptn] == false) {
            ptn += 1;
            continue;
        }
        int s = 2 * ptn;
        while (s <= n) {
            a[s] = false;
            s += ptn;
        }
        ptn += 1;
    }
    vector<int> ret;
    for (int i = 2; i < n + 1; i++) {
        if (a[i]) {
            ret.push_back(i);
        }
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<int> primes = all_prime(n / 2);

    bool selected[n + 1];
    fill(selected, selected + n + 1, false);

    vector<vector<int>> cycle;
    for (auto ptr = primes.rbegin(); ptr != primes.rend(); ptr++) {
        vector<int> temp;
        int this_prime = *ptr;

        for (int j = this_prime; j <= n; j += this_prime) {
            if (selected[j] == false) {
                selected[j] = true;
                temp.push_back(j);
            }
        }

        cycle.push_back(temp);
    }

    int rearrange[n + 1];

    for (int i = 0; i <= n; i++) {
        rearrange[i] = i;
    }

    for (vector<int> swap : cycle) {
        for (int i = 0; i < swap.size() - 1; i++) {
            rearrange[swap[i]] = swap[i + 1];
        }
        rearrange[swap[swap.size() - 1]] = swap[0];
    }

    for (int i = 1; i <= n; i++) {
        cout << rearrange[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}