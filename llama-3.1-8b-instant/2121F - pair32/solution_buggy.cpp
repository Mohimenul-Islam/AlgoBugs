#include <bits/stdc++.h>
 
using namespace std;

// Func that returns number of divisible by k from a to b included


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n, s, x;
        cin >> n >> s >> x;
        vector <long long> V(n);
        for (int i = 0; i < n; i++) {
            cin >> V[i];
        }
        map <long long, int> M;   
        queue <long long>  Q;
        Q.push(0);
        long long roll = 0;
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if(V[i] == x) {
                while(Q.size() > 0) {
                    int a = Q.front();
                    Q.pop();
                    M[a] += 1;
                }   
            }
            roll += V[i];
            Q.push(roll);
            if(V[i] > x) {
                M.clear();
                while (!Q.empty()) {
                    Q.pop();
                }
                Q.push(roll);
            }   
            result += M[roll - s];

        }
        cout << result << '\n';
    }
}