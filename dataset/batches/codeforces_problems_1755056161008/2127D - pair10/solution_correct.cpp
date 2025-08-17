#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back
long long mod=1e9+7;
class tre{
   public:
   vector<vi>a;
   vector<ll>fc;
   int n,id=0,mx=-1;
   ll ans=2LL;
   bool ok=1,pls=0;
   vi leaf,vst;
   tre(int &nn):a(nn),leaf(nn,0),fc(nn+2),vst(nn,0){ 
       n=nn;
       fc[0]=1;
       for(int i=1;i<=n;i++)fc[i]=(fc[i-1]*i)%mod;
   
   }
   void set(int &x,int &y){
       a[x].pb(y);
	   a[y].pb(x);
   }
  
   bool lef(){
      for(int v=0;v<n;v++){
          int sz = a[v].size();
          int nt=0;
          if(sz<2)continue;	
      	for (int j = 0; j < sz; j++) {
	        int u=a[v][j];
            
            int z = a[u].size();
			if (z==1) {
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
       if(nt>=1&&leaf[v]>0){
       pls=true;
       }
       
	  }
        return 0;
   }
   void yes(){
      ans*=fc[mx];
      for(int v=0;v<n;v++){
          if(v==id)continue;
           if(leaf[v]>1)
            ans*=fc[leaf[v]];
            
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
    if(tr.lef()||n<=m){
        cout<<0<<endl;
        return;
    }
    tr.recu(0,-1);
    ll p=1ll;
    if(tr.pls){ 
     p=2ll;
    }
    if(n>2)
    tr.yes();
    
    if(tr.ok)
	   cout <<( p*tr.ans )%mod<< '\n';
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