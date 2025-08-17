#include<bits/stdc++.h>
//#include<windows.h>
#define ll long long
#define pii pair<int,int>
#define inf 2147483647
#define mod 1000000007
using namespace std;
int a[500050];
void SOLVE()
{
    int n;
    cin>>n;
    a[0]=a[n+1]=inf;
    for(int i=1;i<=n;i++)   cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i-1]&&a[i]<a[i+1])    ans+=i;
        else    ans+=i*(n-i+1);
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //struct _timeb T;
    //_ftime(&T);
    //srand(T.millitm);
    //DWORD START=GetTickCount();
    //freopen("../test.in","r",stdin);
    int TT=1;
    cin>>TT;
    while(TT--)	SOLVE();
    //DWORD END=GetTickCount();
    //cout<<"\n----------\ntime: "<<END-START<<"ms";
    return 0;
}