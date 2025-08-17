#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int, int>
#define INF 1000000000000000000LL
#define MOD (int)(998244353)
int powm(int x,int n) {
    x%=MOD;
    if(n==0) return 1; else if(n==1) return x;
    int p = powm(x*x, n/2);
    if(n%2) return p*x%MOD; else return p;
}
 
int mod_div(int p, int q) { return p%MOD * powm(q,MOD-2) % MOD;}

vector<int> fact, ifact;
void factCompute(int N=1e6) {
    fact.assign(N+1, 1);
    ifact.assign(N+1, 1);
    for(int i=1; i<N+1; i++) fact[i] = fact[i-1] * i % MOD;
    ifact[N] = mod_div(1, fact[N]);
    for(int i=N-1; i>=0; i--) ifact[i] = ifact[i+1] * (i+1) % MOD;
}
 
int ncr(int n, int r) {
    if(r > n) return 0;
    return fact[n] * ifact[n-r] % MOD * ifact[r] % MOD;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}

struct Mint
{
    int value;
    static const int MOD_value = MOD;
 
    Mint(long long v = 0)
    {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }
    Mint(long long a, long long b) : value(0)
    {
        *this += a;
        *this /= b;
    }
 
    Mint &operator+=(Mint const &b)
    {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }
    Mint &operator-=(Mint const &b)
    {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }
    Mint &operator*=(Mint const &b)
    {
        value = (long long)value * b.value % MOD;
        return *this;
    }
 
    friend Mint mexp(Mint a, long long e)
    {
        Mint res = 1;
        while (e)
        {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend Mint inverse(Mint a) { return mexp(a, MOD - 2); }
 
    Mint &operator/=(Mint const &b) { return *this *= inverse(b); }
    friend Mint operator+(Mint a, Mint const b) { return a += b; }
    friend Mint operator-(Mint a, Mint const b) { return a -= b; }
    friend Mint operator-(Mint const a) { return 0 - a; }
    friend Mint operator*(Mint a, Mint const b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const b) { return a /= b; }
    friend std::ostream &operator<<(std::ostream &os, Mint const &a) { return os << a.value; }
    friend bool operator==(Mint const &a, Mint const &b) { return a.value == b.value; }
    friend bool operator!=(Mint const &a, Mint const &b) { return a.value != b.value; }
};
 
Mint power(Mint a, ll b)
{
    Mint ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

vector<int> primes;

void seive(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {


        if (prime[p] == true) {
            
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p]) primes.push_back(p);
}

class disjointSet
{
    public:
    int *rank;
    int *parent;
    int *size;
    int capacity;
    disjointSet(int capacity)
    {
        this->capacity = capacity;
        rank = new int[capacity];
        parent = new int[capacity];
        size = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            rank[i] = 0;
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_par(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = find_par(parent[node]);
    }

    void un_rank(int node1, int node2)
    {
        if (find_par(node1) == find_par(node2))
        {
            return;
        }
        int ulp_node1 = find_par(node1);
        int ulp_node2 = find_par(node2);
        if (rank[node1] > rank[node2])
        {
            parent[node2] = node1;
        }
        else if (rank[node1] < rank[node2])
        {
            parent[node1] = node2;
        }
        else
        {
            parent[node2] = node1;
            rank[node1]++;
        }
    }

    void un_size(int node1, int node2)
    {
        int ulp_node1 = find_par(node1);
        int ulp_node2 = find_par(node2);
        if (ulp_node1 == ulp_node2)
        {
            return;
        }
        else if (size[ulp_node1] < size[ulp_node2])
        {
            parent[ulp_node1] = ulp_node2;
            size[ulp_node2] += size[ulp_node1];
        }
        else
        {
            parent[ulp_node2] = ulp_node1;
            size[ulp_node1] += size[ulp_node2];
        }
    }
    void printSize(){
        for(int i=0; i<capacity; i++){
            cout<<parent[i]<<' ';
        }
        cout<<'\n';
    }
};


void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > adj(n);
    vector<int> side(n, -1), cnt_leaf(n, 0), degree(n, 0);
    disjointSet ds(n);
    bool invalid = false;
    for(int i=0, u, v; i<m; i++) {
        cin>>u>>v;
        u--, v--;
        if(side[u] != -1 && side[v] != -1 && side[u] == side[v]) {
            invalid = true;
        } else {
            if(side[u] != -1) side[v] = !side[u];
            else if(side[v] != -1) side[u] = !side[v];
            else side[u] = 0, side[v] = 1;
        }
        ds.un_size(u, v);
        degree[u]++, degree[v]++;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        for(auto& node:adj[i]) if(degree[node] == 1) cnt_leaf[i]++;
    }

    if(m != n-1) {
        cout<<0<<'\n';
        return;
    }
    for(int i=0; i<n; i++) {
        int ndeg = adj[i].size() - cnt_leaf[i];
        if(ndeg >= 3) {
            cout<<0<<'\n';
            return;
        }
    }
    

    map<int, vector<int> > cc;
    for(int i=0; i<n; i++) {
        int par = ds.find_par(i);
        cc[par].push_back(i);
    }

    int num_cc = cc.size();

    //Each Connected Component can be up/down * All the permutation of CCs
    int ans = (powm(2, num_cc)%MOD * fact[num_cc]%MOD)%MOD;

    for(auto&[par, vec]:cc) {
        int t1 =  0, t2 = 0;
        for(auto node: vec) {
            if(cnt_leaf[node]) ans = (ans%MOD*fact[cnt_leaf[node]]%MOD)%MOD;
            t1 += (side[node] == 1), t2 += (side[node] == 0);
        }

        //Mirror image
        if(t1 > 1 && t2 > 1) ans = (ans*2ll)%MOD;
    }

    cout<<ans<<'\n';

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10); cout.setf(ios::fixed);
    cin.tie(NULL);
    factCompute();
    int t;
    cin >> t;
    while (t--) solve();
}