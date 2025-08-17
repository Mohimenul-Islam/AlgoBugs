from sys import stdin,stdout
stdout.reconfigure(line_buffering=False)

def myin():
    return stdin.readline().rstrip()

def myin_sp():
    return stdin.readline().rstrip().split()

def myin_sp_i():
    return list(map(int,myin_sp()))

def myin_sp_s():
    return list(map(str,myin_sp()))

def main():
    from collections import defaultdict
    from random import randint
    RAND_MASK = randint(1,1<<32)
    T = int(myin())
    for _ in [0]*T:
        N,S,X = myin_sp_i()
        A = myin_sp_i()
        ans = 0
        r = -1
        cnt = defaultdict(int) # cnt[i]:=和がiとなる個数
        diff = 0
        for m in range(N):
            # Xとなるmを見つける
            # そこから[l,r]を全探索する
            # rを先に行けるだけ伸ばして，その時のcntを計算しておく
            # その後，lを順に伸ばして，計算
            # もし，前に計算したrよりもmが前にあれば，それを再利用
            diff+=A[m]
            if A[m]==X:
                if r<m:
                    cnt.clear()
                    cnt[0^RAND_MASK] = 1
                    r = m+1
                    diff = 0
                    accum = 0
                    while r<N and A[r]<=X:
                        accum+=A[r]
                        cnt[accum^RAND_MASK]+=1
                        r+=1
                    
                ans+=max(0,cnt[(S+diff-A[m])^RAND_MASK])
                accum = 0
                l = m-1
                while l>=0 and A[l]<X:
                    accum+=A[l]
                    ans+=max(0,cnt[(S+diff-accum-A[m])^RAND_MASK])
                    l-=1
            cnt[diff^RAND_MASK]-=1

        print(ans)
if __name__ == "__main__":
    main()