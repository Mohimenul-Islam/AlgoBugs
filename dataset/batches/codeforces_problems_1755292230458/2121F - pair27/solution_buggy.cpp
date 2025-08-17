//
// Created by admin on 2025/8/6.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

long long x, sum;

int calc(vector<long long> &v) {
    int n = v.size();
    vector<long long> s(n);
    map<long long, int> c;
    for (int i = 0; i < n; i++) {
        s[i] = v[i] + (i ? s[i - 1] : 0);
        c[s[i]]++;
    }
    int res = 0;
    for (int head = 0, i = 0; i < n; i++) {
        while (head < i || (head < n && v[head] < x)) {
            c[s[head]]--;
            head++;
        }
        res += c[sum + (i ? s[i - 1] : 0)];
    }
    return res;
}

void solve() {
    int n;
    cin >> n >> sum >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    for (int i = 0, j = 0; i < n;) {
        if (a[i] > x) {
            i++;
            continue;
        }
        j = i + 1;
        while (a[j] <= x && j < n) j++;
        vector v(a.begin() + i, a.begin() + j);
        res += calc(v);
        i = j;
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
