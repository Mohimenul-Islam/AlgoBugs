#include <iostream>

using namespace std;
int t,n,i,j,dr,v[500003],s[500003],S;
int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        for(j=1;j<=n;j++)
        {
            cin>>v[j];
        }
        s[1]=0;
        for(dr=2;dr<=n;dr++)
        {
            if(v[dr]<v[dr-1])
            {
                s[dr]=s[dr-1]+1;
            }
            else
            {
                s[dr]=s[dr-1];
            }
        }
        for(j=1;j<=n;j++)
        {
            S=S+s[j]*(2*j-1-n);
        }
        cout<<S+n*(n+1)/2<<endl;
        S=0;
    }
    return 0;
}
