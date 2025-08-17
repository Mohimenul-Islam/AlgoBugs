#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
int T,n,m,x,y,i,j,edge[1000010],con[1000010],Head[1000010],tot,cnt,vis[1000010],core[1000010];
struct node
{
  int nxt,p;
}a[1000010];
void AddEdge(int x,int y)
{
  a[++tot].nxt=Head[x];
  Head[x]=tot;
  a[tot].p=y;
}
int dfs(int rt,int x,int dep)
{
  vis[x]=1;
  int dp=0,tmp=0;
//   printf("%d\n",x);
  for(int i=Head[x];i;i=a[i].nxt)
  {
    // printf("%lld %lld\n",i,a[i].nxt);
    if(!vis[a[i].p])
    {
      int len=dfs(rt,a[i].p,dep+1);
      dp=max(len+1,dp);
      if(len>0)tmp++;
    }
  }
  if(dp>0)core[x]++;
  if(tmp>=2)cnt++;
  if(tmp>=3)cnt++;
  return dp;
}
void dfs1(int x)
{
  vis[x]=1;
  con[x]++;
  for(int i=Head[x];i;i=a[i].nxt)
  {
    if(!vis[a[i].p]&&core[a[i].p]==2)
    {
      con[x]++;
      dfs1(a[i].p);
    }
  }
}
int calc(int x)
{
  int res=1;
  for(int i=2;i<=x;i++)
  {
    res=res*i%mod;
  }
  return res;
}
void emp()
{
  for(int i=1;i<=n+n;i++)
    edge[i]=0,con[i]=0,core[i]=0,vis[i]=0,Head[i]=0,a[i].nxt=0;
}
signed main()
{
  scanf("%lld",&T);
  while(T--)
  {
    scanf("%lld%lld",&n,&m);
    // memset
    tot=0;cnt=0;
    for(i=1;i<=m;i++)
    {
      scanf("%lld%lld",&x,&y);
      AddEdge(x,y);
      AddEdge(y,x);
      edge[x]++;edge[y]++;
    }
    if(m!=n-1)
    {
      printf("0\n");
      emp();
      continue;
    }
    dfs(1,1,1);
    // printf("114\n");
    for(i=1;i<=n;i++)
      vis[i]=0;
    if(cnt>1)
    {
      printf("0\n");
      emp();
      continue;
    }
    dfs(2,2,1);
    
    for(i=1;i<=n;i++)
      vis[i]=0;
    for(i=1;i<=n;i++)
    {
      if(core[i]==2)
      {dfs1(i);con[i]--;break;}
    }
    int ans=1,len=0,f=1;
    for(i=1;i<=n;i++)
      if(core[i]==2)
      {
        if(con[i]>2){f=0;break;}
      }
      else if(edge[i]!=1){f=0;break;}
    if(!f)
    {
      printf("0\n");
      emp();
    }
    for(i=1;i<=n;i++)
    {
      if(core[i]==2)
      {
        ans=ans*calc(edge[i]-con[i])%mod;
        // printf("%lld %lld\n",i,edge[i]-con[i]);
        len++;
      }
    }
    if(len>=2)ans=ans*2;
    printf("%lld\n",ans*2%mod);
    for(i=1;i<=n+n;i++)
      edge[i]=0,con[i]=0,core[i]=0,vis[i]=0,Head[i]=0,a[i].nxt=0;
  }
}