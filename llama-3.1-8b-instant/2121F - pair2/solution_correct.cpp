#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using ll= long long;
using namespace __gnu_pbds;
using minheap = priority_queue<long long, vector<long long>, greater<long long>>;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define ll long long
#define ld long double
#define MOD 1000000007
#define pie 2*(acos(0.0))
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb push_back
#define endl '\n'
#define lcm(a,b) (a*b)/(__gcd<ll>(a,b))
#define logb(base,val) log2l(val) / log2l(base)
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
#define printp(v) for(auto e:v) cout<<e.first<<" "<<e.second<<endl;
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define life_is_a_race ios::sync_with_stdio(false); cin.tie(nullptr);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void pbdserase(pbds &t, ll v)
{
    //normal erase function doesnt work in ordered multiset but this works
    int rank = t.order_of_key(v);
    auto it = t.find_by_order(rank);
    t.erase(it);
}

ll calc(vector<ll>&v,ll s,ll x)
{
    ll n = v.size();
    if(n==0) return 0;
    ll ans = 0;
    pbds st;

    vector<ll> sum(n);
    sum[0] = v[0];
    st.insert(sum[0]);

    for(int i=1;i<n;i++) 
    {
        sum[i] = sum[i-1] + v[i];
        st.insert(sum[i]);
    }

    int i=0, ind=-1;
    while(i<n)
    {
        if(ind < i)
        {
            if(ind > -1) pbdserase(st , sum[ind]);
            bool ok = false;
            for(int j=ind+1;j<n;j++)
            {
                if(v[j]==x) 
                {
                    ind = j;
                    ok = true;
                    break;
                }
                pbdserase(st , sum[j]);
            }
            if(!ok) break;
        }
        ll need = sum[i] + s - v[i];
        //for(auto e:st) cout<<e<<' '; cout<<endl;
        ans += st.order_of_key(need+1) - st.order_of_key(need);
        ++i;
    }
    return ans;
}

void solve(int tc)
{
    //cout<<"Case "<<tc<<": ";
    //check N <= 2 cases 
    ll n,s,x; cin >> n >> s >> x;
    vector<ll> v;
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ll e; cin >> e;
        if(e > x)
        {
            ans += calc(v,s,x);
            v.clear();
            continue;
        }
        v.push_back(e);
    }
    ans += calc(v,s,x);
    cout<<ans<<endl;
}

int main()
{
    life_is_a_race
    int t=1; 
    cin>>t;
    for(int i=1;i<=t;i++) solve(i);
}
