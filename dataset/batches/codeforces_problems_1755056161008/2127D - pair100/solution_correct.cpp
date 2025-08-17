#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *find_by_order, order_of_key
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *find_by_order, order_of_key
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Precision cout.precision(10); cout.setf(ios::fixed, ios::floatfield);
#define int long long
#define ld long double
#define allarr arr, arr+n
#define allvec vec.begin(), vec.end()
#define pb push_back
#define pp pop_back
#define vi vector<int>
#define vd vector<ld>
#define mii map<int, int>
#define pii pair<int, int>
#define si set<int>
#define qi queue<int>
#define endl "\n"
#define inf LLONG_MAX
#define eps 1e-6
#define pi 3.14159265358979323846264338327950

const int mod=1e9+7;

// template<class T>
// class DSU{
//     unordered_map<T, T> parent;
//     //set repr -> <set size, set rank>
//     unordered_map<T, pair<int, int>> representative;

//     public:
//     DSU(int n){
//         for(int i=0; i<n; i++){
//             makeSet(i);
//         }
//     }
//     void makeSet(T e){
//         parent[e]=e;
//         representative[e]={1, 0};
//     }
//     T find(T e){
//         if(parent[e]==e) return e;
//         return parent[e]=find(parent[e]);
//     }
//     void unionSet(T e1, T e2){
//         T rep1=find(e1), rep2=find(e2);
//         if(rep1==rep2) return;
//         int rank1=representative[rep1].second;
//         int rank2=representative[rep2].second;
//         if(rank1>rank2){
//             parent[rep2]=rep1;
//             representative[rep1].first+=representative[rep2].first;
//             representative.erase(rep2);
//         }
//         else{
//             parent[rep1]=rep2;
//             representative[rep2].first+=representative[rep1].first;
//             if(rank1==rank2)
//             representative[rep2].second++;
//             representative.erase(rep1);
//         }
//     }
//     int sizeofset(T e){
//         T rep=find(e);
//         return representative[rep].first;
//     }
// };

// int N=1e7+10;
// vector<bool>isprime(N, true);
// void sieve(){
//     isprime[0]=isprime[1]=false;
//     for(int i=2; i<N; i++){
//         if(isprime[i]){
//             for(int j=2*i; j<N; j+=i){
//                 isprime[j]=false;
//             }
//         }
//     }
// }

// vi lp(N, 0), hp(N, 0);
// void lphp(){
//     for(int i=2; i<N; i++){
//         if(isprime[i]){
//             lp[i]=hp[i]=i;
//             for(int j=2*i; j<N; j+=i){
//                 hp[j]=i;
//                 if(lp[j]==0)
//                 lp[j]=i;
//             }
//         }
//     }
// }

// vi prime_factorisation_sieve(int n){
//     vi pf;
//     while(n>1){
//         int i=lp[n];
//         while(n%i==0){
//             pf.push_back(i);
//             n/=i;
//         }
//     }
//     return pf;
// }

// vi divisors(int n){
//     vi div;
//     for (int i=1; i*i<=n; i++){
//         if (n%i==0){
//             div.push_back(i);
//             if(i!=n/i)
//             div.push_back(n/i);
//         }
//     }
//     sort(div.begin(), div.end());
//     return div;
// }

// vi prime_factorisation(int n){
//     vi pf;
//     for(int i=2; i*i<=n; i++){
//         while(n%i==0){
//             pf.push_back(i);
//             n/=i;
//         }
//     }
//     if(n>1)
//     pf.push_back(n);
//     return pf;
// }

// int binExp(int a, int b, int M){
//     int ans=1;
//     while(b){
//         if(b&1)
//         ans=(ans*a)%M;
//         a=(a*a)%M;
//         b>>=1;
//     }
//     return ans;
// }

//Bitmask
// for(int i=0; i<(1<<n); i++){
//     for(int j=n-1; j>=0; j--){
//         if(i&(1<<j))
//     }
// }

// Understand question properly
// Read constraints carefully
// Find a good test case for constructive problems
// Don't complicate the question
// First brute force then optimisation
// Recheck your algorithm

vector<int> fact(200005);

void func(){
    fact[0]=1;
    for(int i=1; i<200005; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}

bool dfs(int v, int c,vector<vector<int>> &adj, vector<int> &color){
    color[v]=c;
    c=(c+1)%2;
    for(int child:adj[v]){
        if(color[child]!=-1 and color[child]!=c)
        return false;
        if(color[child]==-1 and !dfs(child, c, adj, color))
        return false;
    }
    return true;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> degree(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
    if(n-1!=m){
        cout<<0<<endl;
        return;
    }
    vector<int> leaves(n);
    for(int i=0; i<n; i++){
        for(int c:adj[i]){
            if(degree[c]==1)
            leaves[i]++;
        }
    }
    for(int i=0; i<n; i++){
        if(degree[i]-leaves[i]>2){
            cout<<0<<endl;
            return;
        }
    }
    vector<int> color(n, -1);
    if(!dfs(0, 0, adj, color)){
        cout<<0<<endl;
        return;
    }
    int ans=1, val=0;
    for(int i=0; i<n; i++){
        if(degree[i]!=1) val++;
        ans=(ans*fact[leaves[i]])%mod;
    }
    if(val<2)
    ans=(ans*2)%mod;
    else
    ans=(ans*4)%mod;
    cout<<ans<<endl;
}

int32_t main(){
    FastIO;
    func();
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}