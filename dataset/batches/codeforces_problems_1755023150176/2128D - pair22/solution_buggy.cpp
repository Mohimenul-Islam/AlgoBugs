#include <iostream>
#include <vector>
//#include<cmath>
//#include <algorithm>
//#include <string>
//#include<queue>
//#include<map>
//#include<set>
//#include<ctime>

using namespace std;


void alg()
{
    int n;

    cin >> n;

    vector<long long> a(n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp_amount(n, 0);
    vector<int> dp_length(n, 0);
    long long res = 0;

    dp_amount[0] = 1;
    dp_length[0] = 1;
    res += dp_length[0];

    if (a[0] > a[1])
    {
        dp_amount[1] = 2;
        dp_length[1] = dp_length[0] + dp_amount[1];

        res += dp_length[1];  // [0, 1]
    }
    else
    {
        dp_amount[1] = 1;
        dp_length[1] = 1;
        
        res += dp_length[0];  // [0, 1]
        res += dp_length[1];  // [1, 1]

        dp_amount[1]++;
        dp_length[1]++;
    }

    for (int pos = 2; pos < n; pos++)
    {
        if (a[pos - 1] > a[pos])
        {
            dp_amount[pos] = dp_amount[pos - 1] + 1;
            dp_length[pos] = dp_length[pos - 1] + dp_amount[pos];

            res += dp_length[pos];
        }
        else
        {
            dp_amount[pos] = dp_amount[pos - 2] + 1 + 1;
            dp_length[pos] = dp_length[pos - 2] + dp_amount[pos];

            res += dp_length[pos];
        }
    }

    cout << res << endl;
}

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
        alg();

}
