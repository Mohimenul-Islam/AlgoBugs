#include <iostream>
#include <cstdint>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <memory>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int a[200002];
int pre[200002];

void solution() {
	int n, s, x;
	cin >> n >> s >> x;
	pre[1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i + 1] = pre[i] + a[i];
	}

	int64_t ans = 0;

	int l = 0, r = 0;

	std::map<int, int> cout_pre;

	int left = 0, right = 0;

	for (int right = 1; right <= n; right++) {
		if (a[right] > x) {
			left = right;
			cout_pre.clear();
		}
		else if (a[right] == x) {
			while (left < right) {
				cout_pre[pre[left + 1]]++;
				left++;
			}
		}

		ans += cout_pre[pre[right + 1] - s];
	}


	cout << ans << endl;
}

int main()
{
	int t;
	scanf_s("%d", &t);

	while (t--) {
		solution();
	}
	
	return 0;
}

/*
9
1 0 0
0
1 -2 -1
-2
3 -1 -1
-1 1 -1
6 -3 -2
-1 -1 -1 -2 -1 -1
8 3 2
2 2 -1 -2 3 -1 2 2
9 6 3
1 2 3 1 2 3 1 2 3
13 7 3
0 -1 3 3 3 -2 1 2 2 3 -1 0 3
2 -2 -1
-2 -1
2 -2 -1
-1 -2

*/
