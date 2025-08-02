#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, a[100005];
        cin>>n;
        for(int i = 0; i < n; i ++)
        {
            cin>>a[i];
        }
        int l = 1, r = n - 1, pre = 0;
        cout<<'L';
        while(l <= r)
        {
            if(l == r)
            {
                cout<<"L";
                break;
            }
            if((a[l] - a[pre] < 0) == (a[l] - a[r] < 0))
            {
                cout<<"LR";
                pre = r --;
                l ++;
            }
            else
            {
                cout<<"RL";
                pre = l++;
                r --;
            }
        }
        cout<<'\n';
    }

}
