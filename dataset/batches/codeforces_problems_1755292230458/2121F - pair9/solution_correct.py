def solve():
    import sys
    t=int(sys.stdin.readline())
    def f(b,s,x):
        l=len(b)
        if not l: return 0
        p=[0]*(l+1)
        for i in range(l):
            p[i+1]=p[i]+b[i]
        lx=[-1]*l
        c=-1
        for i in range(l):
            if b[i]==x:
                c=i
            lx[i]=c
        d={}
        r=0
        j=0
        for i in range(l):
            if lx[i]==-1: continue
            while j<=lx[i]:
                d[p[j]]=d.get(p[j],0)+1
                j+=1
            r+=d.get(p[i+1]-s,0)
        return r
    for _ in range(t):
        n,s,x=map(int,sys.stdin.readline().split())
        arr=list(map(int,sys.stdin.readline().split()))
        ans=0
        tmp=[]
        for v in arr:
            if v>x:
                ans+=f(tmp,s,x)
                tmp=[]
            else:
                tmp.append(v)
        ans+=f(tmp,s,x)
        print(ans)

solve()
