#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;

const ll st=200005,mod = 998244353;

int n;
int tab[500005];
int dp[500005];


void antekb_to_nob()
{
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>tab[i];
    }
    dp[0] = 1;
    ll res = 1;
    for(int i=1;i<n;i++) {
        if(tab[i] < tab[i-1]) {
            dp[i] = dp[i-1] + i + 1;
        }
        else {
            dp[i] = dp[i-1] + 1;
        }
        res += dp[i];
    }

    cout<<res<<"\n";

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
		antekb_to_nob();
	}
    
    
    
   

    return 0;
}





