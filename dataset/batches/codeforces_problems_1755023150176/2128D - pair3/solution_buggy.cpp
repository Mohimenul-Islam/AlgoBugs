#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        int sum = (n * (n + 1) * (n + 2))/6;
        for (int i = 0; i + 1 < n; ++i)
        {
            if (v[i] < v[i + 1])
            {
                sum -= (i + 1) * (n - i - 1);
            }
        }
        cout << sum << endl;
    }
    return 0;
}
