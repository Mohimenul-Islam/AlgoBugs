#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define f(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll LINF = 1e18;
const int M = 5800080;
/*-------------------------------------------------------------------------------------*/
vi prime;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// typedef __gnu_pbds::tree<
//     int,
//     __gnu_pbds::null_type,
//     std::less<int>,
//     __gnu_pbds::rb_tree_tag,
//     __gnu_pbds::tree_order_statistics_node_update>
//     ordered_set;

template <typename T>
std::istream &operator>>(std::istream &stream, vector<T> &vec)
{
    for (T &x : vec)
        stream >> x;
    return stream;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector<T> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        stream << vec[i];
        if (i != vec.size() - 1)
            stream << ' ';
    }
    return stream;
}

/*-------------------------------------------------------------------------------------*/
void generateprime(int N, vector<int> &primes)
{
    // vector<int> primes; // Initialize an empty vector to
    //  store prime numbers
    primes.push_back(2); // Add 2 as the first prime number
    int num = 3;         // Start checking for prime numbers from 3
    while (primes.size() < N)
    {                         // Keep searching until we
                              // find N prime numbers
        bool is_prime = true; // Assume the current number is prime
                              // until proven otherwise
        for (int i = 0; i < primes.size(); i++)
        {
            if (num % primes[i] == 0)
            {                     // If the current number is
                                  // divisible by any previously found
                                  // prime numbers
                is_prime = false; // Then it is not a prime
                                  // number
                break;            // Exit the loop since we've already
                                  // proven it's not prime
            }
        }
        if (is_prime)
        {                          // If the current number is still
                                   // prime after checking all
                                   // previously found prime numbers
            primes.push_back(num); // Add it to our vector
                                   // of prime numbers
        }
        num += 2; // Check the next odd number (since even
                  // numbers other than 2 are not prime)
    }
}
void seive(vector<int> &v)
{
    vector<bool> is_prime(M + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime

    for (int i = 2; i <= M; i++)
    {
        if (is_prime[i])
        {
            v.pb(i);
            for (int j = 2 * i; j <= M; j += i)
                is_prime[j] = false;
        }
    }

    // Printing the prime numbers
}
void yes()
{
    cout << "YES" << '\n';
}
void no()
{
    cout << "NO" << '\n';
}

ll gcd(ll a, ll b)
{
    // Euclidean algorithm
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    // cout<<"krj"<<endl;
    // cout<<a<<endl;
    return a;
}
ll lcm(ll a, ll b)
{
    ll k = gcd(a, b);
    return (a / k) * b;
}
ll kadane(vector<ll> &nums)
{
    ll maxSoFar = INT_MIN;
    ll maxEndingHere = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        maxEndingHere += nums[i];
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }

    return maxSoFar;
}
ll add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m) + m) % m; }
ll sub(ll a, ll b, ll m = MOD) { return ((a % m) - (b % m) + m) % m; }
ll mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
ll modexp(ll a, ll e, ll m = MOD)
{

    a %= m;
    ll r = 1;
    while (e)
    {
        if (e & 1)
            r = mul(r, a, m);
        a = mul(a, a, m);
        e >>= 1;
    }
    return r;
}
ll inv(ll a, ll m = MOD) { return modexp(a, m - 2, m); }
const int N = 4e5 + 2;
vector<int> fact(N);
void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}
int nck(int n, int k)
{
    if (n < k)
        return 0;
    if (n == k || k == 0)
        return 1;
    // n!/k!(n-k)!
    int res = mul(fact[n], inv(mul(fact[k], fact[n - k])));
    return res;
}
int dig_sum(int k)
{
    int res = 0;
    while (k)
    {
        res += k % 10;
        k /= 10;
    }
    return res;
}
ll D(ll x,ll y){
    return x*x-4*y;
}
void solve()
{
    // dpi is the lds such that i is the starting point
    // since either ai or ai+1 swill be the max of suffix
    // if ai>ai+1
    //dpi=di+1+n-i(no of time i is used)
    // else start with dpi+1
    //dpi=dpi+2+n-i
    //fin ans=sum
    //dp[n-1]=1;
    int n;
    cin>>n;
    ll cur=1,prev=0;
    vi v(n);
    cin>>v;
    ll ans=1;
    for(int i=n-2;i>=0;i--){
        ll now;
        if(v[i]>v[i+1]) now=cur+n-i;
        else now=prev+n-i;
        ans+=now;
        prev=cur;
        cur=now;
    }
    cout<<ans<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1
    int t = 1;
    // precompute();
    cin >> t; // Comment this line if there's only one test case
    // seive(prime);

    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}
/*
 ██████╗ ██████╗     ██╗  ██╗██████╗ ██╗███████╗██╗  ██╗
██╔═══██╗██╔══██╗    ██║ ██╔╝██╔══██╗██║██╔════╝██║  ██║
██║   ██║██████╔╝    █████╔╝ ██████╔╝██║███████╗███████║
██║   ██║██╔═══╝     ██╔═██╗ ██╔══██╗██║╚════██║██╔══██║
╚██████╔╝██║         ██║  ██╗██║  ██║██║███████║██║  ██║
 ╚═════╝ ╚═╝         ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚══════╝╚═╝  ╚═╝

                O p ~ K r i S h
*/