#include<bits/stdc++.h>
//#define f first
//#define s second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX=2e5+10,mod=1e9+7;
int t;
ll n,s,x;
ll a[MAX];
ll sum[MAX];
map<ll,int> mii;
ll ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&s,&x);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1,l=0;i<=n;i++){
			if(a[i]>x){l=i;mii.clear();}
			else if(a[i]==x){
				while(l<i){mii[sum[l++]]++;}
			}ans+=mii[sum[i]-s];
		}printf("%lld\n",ans);
		ans=0,mii.clear();
	}
	return 0;
}