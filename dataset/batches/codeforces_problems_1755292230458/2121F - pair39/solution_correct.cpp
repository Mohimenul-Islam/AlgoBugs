#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+5;
const int INF=1e16;
int t,n,s,x,ans;
int a[maxn];
int f[maxn];
map<int,int> cnt;
void init(){
	ans=0;
	cnt.clear();
	for(int i=1;i<=n+1;i++) a[i]=0;
	
}
void solve(){
//	cnt++;
	cin >> n >> s >> x;
	init();
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n+1;i++){
		f[i]=f[i-1]+a[i];
	}
	int l=1;
	for(int r=1;r<=n;r++){
		if(a[r]>x){
			cnt.clear();
			l=r+1;	
		}
		else if(a[r]==x){
			while(l<=r){
				cnt[f[l-1]]++;
				l++;
			}
		}
		ans+=cnt[f[r]-s];
	}
	cout << ans << endl;
}
signed main(){
//	freopen("in.in","r",stdin);
	cin >> t;
	while(t--) solve();
	return 0;
}