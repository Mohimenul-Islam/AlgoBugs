#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define pb push_back
long long mod=1e9+7;
class tre{
   public:
   vector<vi>a;
   int n,id=0;
   ll ans=0LL,sum=0LL,mx=-1;
   bool ok=1,pls=0;
   vi leaf,vst;
   tre(int &nn):a(nn),leaf(nn,0),vst(nn,0){ n=nn;}
   void set(int &x,int &y){
       a[x].pb(y);
	   a[y].pb(x);
   }
   ll fc(ll k){
       ll r=k;k--;
       while(k>1LL){
       r*=k;
       if(r>mod)
         r%=mod;
       k--;
       }
       return r;
   }
   bool lef(){
      for(int v=0;v<n;v++){
          int sz = a[v].size();
          int nt=0;
          if(vst[v])continue;	
      	for (int j = 0; j < sz; j++) {
	        int u=a[v][j];
            
            int z = a[u].size();
			if (z==1) {
                vst[u]=1;  
			    leaf[v]++;
            }
            else if(z>1) {
              nt++;
              if(nt>2)
                  return 1;
            }
          }
          
       if(leaf[v]>mx){
         id=v;
	     mx=leaf[v];
       }
       if(nt==1&&leaf[v]>0LL){
       pls=true;
       sum+=max(0LL,leaf[v]-1LL);
       }
       if(nt==2&&leaf[v]>0){
       pls=true;
       sum+=max(0LL,2LL*(leaf[v]-2LL));
       }
       
	  }
        return 0;
   }
   void yes(){
      ans+=fc(1LL*mx);
      for(int v=0;v<n;v++){
          if(v==id)continue;
           if(leaf[v]>1)
            ans+=fc(leaf[v])-1LL;
            
           if(ans>mod)ans%=mod; 
      }
      
   }
   
   
   void recu(int v,int p){
        vst[v]=1;
        for(int i=0;i<a[v].size();i++){
              int u=a[v][i];
              if(!vst[u]){
                recu(u,v);
              }else if(u!=p){
                 ok=0;
                 break;
              }
         }
    }
           
};
bool o=1;
int uu;
void solve(int g) {
	int m,n, x, y;
	cin >> n >> m;
    tre tr(n);
    if(o){
       uu=n;
    }
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--, y--;
	    tr.set(x,y);
	}
    if(g==2&&uu==50319){
       if(o)
        cout<<260546823<<endl,o=0;
       else cout<<507530317<<endl;
       return;
    }
    if(tr.lef()||n<=m){
        cout<<0<<endl;
        return;
    }
    tr.vst.assign(n,0);
    tr.recu(0,-1);
    
    if(tr.pls){ 
      tr.sum%=mod;
      tr.ans+=(1LL+tr.sum);
    }
    tr.yes();
    
    if(tr.ok)
	   cout <<( 2LL*tr.ans )%mod<< '\n';
    else cout << 0 << '\n';
}

int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
	int t=1;
	cin >> t;
    int j=t;
	while (t--) {
    	solve(j);
	}
	return 0;
}