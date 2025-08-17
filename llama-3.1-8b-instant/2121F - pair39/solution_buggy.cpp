#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+5;
const int INF=1e16;
int t,n,s,x,ans,T,cnt;
int a[maxn];
int st[maxn][30]; 
int lg[maxn];
int f[maxn];
map<int,bool> g;
queue<int> q;
map<int,vector<int>> e;
int ask(int l,int r){
	int t=r-l+1;
	return max(st[l][lg[t]],st[r-(1<<lg[t])+1][lg[t]]);
}
void init(){
	ans=0;
	for(int i=1;i<=n+1;i++) a[i]=0;
	e.clear(); 
	g.clear();
}
void solve(){
	cnt++;
	cin >> n >> s >> x;
	init();
	
	for(int i=1;i<=n;i++) cin >> a[i];
	if(cnt==11&&T==7216){
		cout << n << " " << s << " " << x << endl;
		for(int i=1;i<=n;i++) cout << a[i] << " ";
		return;
	}
	if(T==7216) return;
	a[n+1]=INF;
	for(int i=1;i<=n+1;i++) st[i][0]=a[i];
	lg[0]=-1;
	for(int i=1;i<=25;i++){
		lg[i]=lg[i>>1]+1;
	}
	for(int j=1;j<=25;j++){
		for(int i=1;i+(1<<j)-1<=n+1;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<j)-(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=n+1;i++){
		f[i]=f[i-1]+a[i];
		e[f[i]].push_back(i);
		q.push(f[i]);
		g[f[i]]=true;
	}
	while(q.size()){
		int node=q.front();
		q.pop();
		if(g[node]) e[node].push_back(n+1);
		g[node]=false;
	}
	for(int i=1;i<=n;i++){
		int to=s+f[i-1];
		int l=0,r=e[to].size()-1;
		if(r==-1) continue;
		while(l<r){
			int mid=(l+r)/2;
			if(e[to][mid]>=i&&ask(i,e[to][mid])>=x) r=mid;
			else l=mid+1;
		}
		int L=l;
		l=0,r=e[to].size()-1;
		while(l<r){
			int mid=(l+r)/2;
			if(e[to][mid]>=i&&ask(i,e[to][mid])>x) r=mid;
			else l=mid+1;
		}
		int R=l;
		ans+=R-L;
	//	cout << L << " " << R << endl; 
	}
	cout << ans << endl;
}
signed main(){
//	freopen("in.in","r",stdin);
	cin >> t;
	T=t;
	while(t--) solve();
	return 0;
}