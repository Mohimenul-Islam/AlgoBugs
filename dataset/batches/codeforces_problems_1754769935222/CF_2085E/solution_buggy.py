class Counter:
   def __init__(self, maxlen):
      self.C = [0]*maxlen
      self.nonzero = 0
      self.log = []

   def _set(self, k, v):
      assert 0 <= k < len(self.C)
      self.nonzero -= (self.C[k] != 0)
      self.C[k] = v
      self.nonzero += (self.C[k] != 0)

   def __setitem__(self, k, v):
      self.log.append(k)
      self._set(k, v)

   def __getitem__(self, k):
      assert 0 <= k < len(self.C)
      return self.C[k]

   def __len__(self):
      return len(self.log)

   def reset(self):
      for k in self.log:
         self._set(k, 0)
      self.log.clear()

   def any(self):
      return 1 <= self.nonzero

   def all(self):
      return self.nonzero == len(self.C)


C = Counter(10**6)


def solve(A, B):
   def check(d):
      for a in A:
         C[a%d] += 1
      for b in B:
         C[b] -= 1

      if C.any():
         C.reset()
         return 0
      C.reset()
      return 1

   U = max(A) + 1
   diff = abs(sum(A) - sum(B))
   if diff == 0:
      if check(U):
         return U
      return -1

   for d in divisors(diff):
      if not d <= U: continue
      if check(d):
         return d
   return -1


from collections import defaultdict


def factors(X: int):
   assert X >= 1
   F: list[tuple[int, int]] = []
   p = 2
   while p*p <= X:
      e = 0
      while X%p == 0:
         e += 1
         X //= p
      if e != 0:
         F.append((p, e))
      p += 1 + (p%2)
   if X != 1:
      F.append((X, 1))
   return F


def divisors_from_factors(F: list[tuple[int, int]], *, sort=True):
   D = [1]
   for p, e in F:
      nD = D[:]
      pow = p
      for _ in range(1, e+1):
         nD.extend([pow*d for d in D])
         pow *= p
      D = nD
   if sort:
      D.sort()
   return D


def divisors(X, *, sort: bool = True):

   return divisors_from_factors(factors(X), sort=sort)


Q = int(input())
ans = []
for _ in range(Q):
   N = int(input())
   A = list(map(int, input().split()))
   B = list(map(int, input().split()))
   res = solve(A, B)
   ans.append(res)
for res in ans:
   print(res)
