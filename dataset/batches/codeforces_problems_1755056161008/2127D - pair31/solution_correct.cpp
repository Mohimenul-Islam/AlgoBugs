//1.检查数组是否开小
//2.写拍!尤其是图论题!一定要写拍子!!
//3.注意开题顺序!先写暴力!
//4.细节想清楚再写题!!!
//5.不要睡觉!!!
//6.增量法可不可以一次增少点??
//7.暴力打满乎??
//8.数数题毫无思路??打个表先??
//9.做法太麻烦?换个做法?能不能二分?能不能考虑贡献??
//10.拼暴力检查有没有拼错!!
//11.不确定的题，一定要早几组全面的小数据看看!!!
//12.要删数的题？删干净了没有!!!检查!!!
//13.绑暴力!!
//14.想想自己是否复杂度吊打了std???真的对吗??
//15.要不要拍点大数据??要不要构造点数据??
//16.真的不会做??能不能随机??
//17.不要对题目难度有任何预设!!
//18.被卡常了??最优化问题能不能剪??数组是不是不连续??
//19.暴力和暴力也要拍!!猜结论最好打个表，不要手造小数据就瞎猜!!
//20.树形 dp 调不出来？？换几个根试试!!!

#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5,mod=1e9+7;
void chkmax(int &x,int y){x=max(x,y);}
void chkmin(int &x,int y){x=min(x,y);}
void Add(int &x,int y){x+=y,x%=mod;}
int ab(int x){if(x<0)x=-x;return x;}

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}

int n,m,d[N],dep[N],fac[N],ans=1;
vector<int>e[N];

void Dfs(int x,int fa){
	int s=0;
	for(auto v:e[x]){
		if(v==fa)continue;
		s++,Dfs(v,x);
	}
	ans=1ll*ans*fac[s]%mod;
}

int main(){
	fac[0]=1;
	for(int i=1;i<=200000;i++)fac[i]=1ll*fac[i-1]*i%mod;
	int T=read();
	while(T--){
	  n=read(),m=read(),ans=1;	
		for(int i=1;i<=m;i++){
	  	int u=read(),v=read();
	  	d[u]++,d[v]++;
	  	e[u].push_back(v),e[v].push_back(u);
		}	
	  if(m!=n-1)printf("0\n");
	  else {
			for(int i=1;i<=n;i++){
			  int s=0,mx=0;
				for(auto v:e[i])s+=d[v]==1,mx+=d[v]>1;
				ans=1ll*ans*fac[s]%mod;
				if(mx>2)ans=0;
			}
			int g=0;
			for(int i=1;i<=n;i++)g+=d[i]>1;
			if(g>1)ans=ans*2%mod;
			printf("%d\n",ans*2%mod);
		}
		for(int i=1;i<=n;i++)d[i]=0,e[i].clear();
	} 
	return 0;
}
//start coding at
//finish coing at
//accept at