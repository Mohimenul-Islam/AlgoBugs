#include <bits/stdc++.h>
#include <vector>
#define test int t;cin>>t;while(t--)
using namespace std; 
bool isPrime(long long n) {
    auto modmul = [&](long long a, long long b, long long mod) {
        long long res = 0;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = (res + a) % mod;
            a = (a + a) % mod;
            b >>= 1;
        }
        return res;
    };

    auto modpow = [&](long long base, long long exp, long long mod) {
        long long res = 1 % mod;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = modmul(res, base, mod);
            base = modmul(base, base, mod);
            exp >>= 1;
        }
        return res;
    };

    if (n < 2) return false;
    for (long long p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
        if (n % p == 0) return n == p;

    long long d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, s++;

    for (long long a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) continue;
        long long x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = modmul(x, x, n);
            if (x == n - 1) { composite = false; break; }
        }
        if (composite) return false;
    }
    return true;
}




int main(){
    test{
        long long l,r;cin>>l>>r;
        long long div2 = r/2 - l/2;
        long long div3 = r/3 - l/3;
        long long div5 = r/5-l/5;
        long long div7 = r/7-l/7;
        long long div23 = r/6 - l/6; 
        long long div25=r/10 - l/10; 
        long long div27 = r/14 - l/14; 
        long long div35 = r/15 - l/15; 
        long long div37 = r/21 - l/21; 
        long long div57 = r/35 -  l/35;
        long long div235 = r/30 - l/30;
        long long div357 = r/105 - l/105;
        long long div572 = r/70 - l/70;
        long long div723 = r/42 - l/42;
        long long div2357 = r/210 - l/210;
        long long ans = div2+div3+div5+div7-div23-div35-div57-div25-div27-div37+div235+div357+div572+div723-div2357;
        int cnt=0;
        ans=r-l-ans;
        if(isPrime(l) && l>7) ans++;
        cout<<ans<<"\n";
    }
return 0;
}