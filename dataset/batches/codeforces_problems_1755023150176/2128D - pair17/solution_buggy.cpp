#include<bits/stdc++.h>
using namespace std;
#define elif else if

const int sizen = 2e6+11;
int N,t;
int T[sizen];
int dp[sizen];
void solve()
{
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> T[i];
    }
    dp[N-1] = 1;
    dp[N] = 0;
    for(int i = N-2 ; i >= 0 ;i--)
    {
        if(T[i] > T[i+1])
        {
            dp[i]= dp[i+1]+N-i; 
        }
        elif(1)
        {
            dp[i] = dp[i+2]+N-i; 
        }
    }
    int w = 0 ;
    for (int i = 0 ; i < N;  i++)
    {
        w+=dp[i];
    }
    cout << w << "\n";
}
signed main()
{
    cin >> t;
    while(t-->0)
    {
        solve();
    }
}