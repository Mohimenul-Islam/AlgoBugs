#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;

const ll st=200005,mod = 998244353;

int n;
int tab[200005];

void antekb_to_nob()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>tab[i];

    bool res = true;
    int mini = 0;

    for(int i=n-1;i>=0;i--) {
        res &= tab[i] >= mini;
        if(tab[i] == 1) {
            mini = max(mini,1);
            continue;
        }
        if(tab[i]%2==0)
            mini = max(mini,tab[i]/2+1);
        else
            mini = max(mini,tab[i]/2+1);
    }

    if(res)
        cout<<"YES\n";
    else {
        cout<<"NO\n";
    }

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





