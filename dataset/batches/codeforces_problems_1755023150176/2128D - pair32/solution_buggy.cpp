#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	int t; cin >> t;
	for (int it = 0; it < t; it++) {
		int n; cin >> n; 
		long long ret = n;
		int first; cin >> first;
		for (int i = 0; i < n - 1; i++) {
			int second; cin >> second;
			if (second < first) {
				long long k = (i + 1) * (n - i);
				ret += k;
			}
			else {
				ret += i + 1;
			}
			first = second;
		}
		cout << ret << endl;
	}
}