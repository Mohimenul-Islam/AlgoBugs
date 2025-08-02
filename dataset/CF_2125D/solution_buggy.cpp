                            //                                  ****Mr HGA उर्फ ऋतिक गडरियाल आनंद****
                            //                                                ¯\(ツ)/¯
                    //                                         ⠀⠀⠀⠀⠀⢀⣤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⢤⣤⣀⣀⡀⠀⠀⠀⠀⠀⠀
                    //                                         ⠀⠀⠀⢀⡼⠋⠀⣀⠄⡂⠍⣀⣒⣒⠂⠀⠬⠤⠤⠬⠍⠉⠝⠲⣄⡀⠀⠀
                    //                                         ⠀⠀⢀⡾⠁⠀⠊⢔⠕⠈⣀⣀⡀⠈⠆⠀⠀⠀⡍⠁⠀⠁⢂⠀⠈⣷⠀⠀
                    //                                         ⠀⣠⣾⠥⠀⠀⣠⢠⣞⣿⣿⣿⣉⠳⣄⠀⠀⣀⣤⣶⣶⣶⡄⠀⠀⣘⢦⡀
                    //                                         ⡞⡍⣠⠞⢋⡛⠶⠤⣤⠴⠚⠀⠈⠙⠁⠀⠀⢹⡏⠁⠀⣀⣠⠤⢤⡕⠱⣷
                    //                                         ⡇⠇⣯⠤⢾⡙⠲⢤⣀⡀⠤⠀⢲⡖⣂⣀⠀⠀⢙⣶⣄⠈⠉⣸⡄⠠⣠⡿
                    //                                         ⠹⣜⡪⠀⠈⢷⣦⣬⣏⠉⠛⠲⣮⣧⣁⣀⣀⠶⠞⢁⣀⣨⢶⢿⣧⠉⡼⠁
                    //                                         ⠀⠈⢷⡀⠀⠀⠳⣌⡟⠻⠷⣶⣧⣀⣀⣹⣉⣉⣿⣉⣉⣇⣼⣾⣿⠀⡇⠀
                    //                                         ⠀⠀⠈⢳⡄⠀⠀⠘⠳⣄⡀⡼⠈⠉⠛⡿⠿⠿⡿⠿⣿⢿⣿⣿⡇⠀⡇⠀
                    //                                         ⠀⠀⠀⠀⠙⢦⣕⠠⣒⠌⡙⠓⠶⠤⣤⣧⣀⣸⣇⣴⣧⠾⠾⠋⠀⠀⡇⠀
                    //                                         ⠀⠀⠀⠀⠀⠀⠈⠙⠶⣭⣒⠩⠖⢠⣤⠄⠀⠀⠀⠀⠀⠠⠔⠁⡰⠀⣧⠀
                    //                                         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠲⢤⣀⣀⠉⠉⠀⠀⠀⠀⠀⠁⠀⣠⠏⠀
                    //                                         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠛⠒⠲⠶⠤⠴⠒⠚⠁⠀⠀
                            #include <bits/stdc++.h>
                            #include <ext/pb_ds/assoc_container.hpp>
                            using namespace __gnu_pbds;
                            #define nl '\n'
                            #define F first
                            #define S second
                            #define vvi vector<vector<int>>
                            #define ll long long
                            #define ld long double
                            #define pb push_back
                            #define rz resize
                            #define M_E 2.71828182845904523536
                            #define M_PI 3.14159265358979323846
                            #define mp make_pair
                            #define vpii vector<pair<int, int>>
                            #define pii pair<int, int>
                            #define pll pair<long long, long long>
                            #define vi vector<int>
                            #define all(x) x.begin(), x.end()
                            #define vl vector<long long>
                            #define mii map<int, int>
                            #define debug(x)       \
                                cerr << #x << " "; \
                                cerr << x;         \
                                cerr << endl;
                            #define pqb priority_queue<int>
                            #define IOS                           \
                                ios_base::sync_with_stdio(false); \
                                cin.tie(NULL);                    \
                                cout.tie(NULL);
                            #define rsort(a) sort(a.rbegin(), a.rend())
                            #define get_sum(a) accumulate(a.begin(), a.end(), 0LL)
                            #define get_max(a) *max_element(a.begin(), a.end())
                            #define get_min(a) *min_element(a.begin(), a.end())
                            #define setbits(x) __builtin_popcountll(x)
                            #define print(a)          \
                                for (auto &i : a)     \
                                    cout << i << " "; \
                                cout << nl;
                            #define int long long int
                            using namespace std;
                            #define mod (int)(2e6+1)
                            #define w(t)  \
                                int t;    \
                                cin >> t; \
                                while (t--)
                            #define f(i, x, y) for (int i = x; i < y; i++)
                            typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds; // reater v kr sakte
                            //(find_by_order and order_of_key)
                            std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
                            template <typename T>
                            istream &operator>>(istream &stream, vector<T> &a)
                            {              // if the size of vector is not given before hand
                                a.clear(); // remove whatever was in a before
                                string line; // how to use? vector<int> v; cin>>v; that's it (if elements are givenin a single line)
                                do
                                {
                                    if (stream.eof())
                                        return stream; // if the stream has ended, just let a be empty
                                    getline(stream, line);
                                } while (line.empty());
                                istringstream line_stream(line);
                                T x;
                                while (line_stream >> x)
                                    a.push_back(x);
                                return stream;
                            }
                            const int inf = LLONG_MAX;
                            const int modi = 998244353;
                            const int modi1 = 1000000007;
                            //*//
                            // int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
                            // int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
                            //            { U  , D ,  L  , R , UL  , UR  , DL  , DR }
                            //*//
                            struct tt
                            {
                                int first, second, third;
                            };
                            struct tits
                            {
                                bool operator()(const tt &a, const tt &b) const
                                {
                                    // return a.first < b.first;   //for max heap
                                    return a.first > b.first; // for min heap
                                }
                            };
                            // interactive problem ke liye chup chap question cout kro and res cin krne ke baadcout<<endl; hat's it
                            // rest is logic
                            // class solution{
                            // public:
                            // void answer(){
                            // }
                            // };

int n,m;
vector<vector<int>> ran;
vector<int> num,den;
bool cmp(vector<int> &a,vector<int> &b){
    if(a[0] == b[0]) return a[1]<b[1];
    return a[0]<b[0];
}
int pp(int a,int b){
    int ans = 1;
    while(b){
        if(b&1) (ans*=a)%=modi;
        b>>=1;
        (a*=a)%=modi;
    }
    return ans;
}
void mrhga(){
cin>>n>>m;
int xtra = 1;
for(int i=0;i<n;i++){
    int a,b,c,d; cin>>a>>b>>c>>d;
    ran.pb({a,b,i}); num.pb(c); den.pb(d); 
    int val = (d - c + modi)%modi;
    (val*=pp(d,modi-2))%=modi;
    (xtra*=val)%=modi;
}
sort(all(ran),cmp);
if(ran[0][0]!=1) {cout<<0<<nl; return;}
auto fun1 = [&](int val)->int{
    int ans = n;
    int l = 0,r=n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(ran[mid][0] >= val) {ans = mid; r=mid-1;}
        else l = mid+1;
    }
    if(ans == n) return ans;
    if(ran[ans][0] == val) return ans;
    return n;
};
auto fun2 = [&](int val)->int{
    int ans = -1;
    int l = 0,r=n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(ran[mid][0] <= val) {ans = mid; l=mid+1;}
        else r=mid-1;
    }
    if(ans == -1) return ans;
    if(ran[ans][0] == val) return ans;
    return -1;
};
vector<int> state(n,-1);
for(int u=0;u<n;u++){
    state[u] = num[ran[u][2]];
    int kk = (den[ran[u][2]] - num[ran[u][2]] + modi) %modi;
    (state[u] *= pp(kk,modi-2))%=modi;
}
vector<int> dp(n+1,0);
for(int i=n-1;i>=0;i--){
    int p = ran[i][1]+1;
    int st = fun1(p);
    int end = fun2(p);
    int val = 0;
    bool flag= 0;   
    for(int j=st;j<=end;j++){
        flag = 1;
        (val+=dp[j])%=modi;
    }
    if(flag) dp[i] = (state[i] * val)%modi;
    if(!flag){
        if(ran[i][1]!=m) dp[i]=0;
        else dp[i] = state[i];
    }
}
int ans = 0;
int st = fun1(1);
int end = fun2(1);
for(int u=st;u<=end;u++){
  (ans+=dp[u])%=modi;
}
cout<<(xtra * ans)%modi<<nl;
}
                
                        // void hakku(int t){
                        //     for(int i=1;i<=t;i++){
                        //         cout<<"Case #"<<i<<": ";
                        //         solve();
                        //     }
                        // }

        int32_t main(){
            IOS 
            // freopen("input.txt", "r", stdin);
            // freopen("output.txt", "w", stdout);
            int t;
            t = 1;
            // cin.operator>>(t);  
            while (t--)
            {
                mrhga();
            }
            // hakku(t);
        }



                        //   ───────────────────────────────────────────────────────────────────────────────────────────
                        //   ─██████──────────██████─████████████████──────██████──██████─██████████████─██████████████─
                        //   ─██░░██████████████░░██─██░░░░░░░░░░░░██──────██░░██──██░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─
                        //   ─██░░░░░░░░░░░░░░░░░░██─██░░████████░░██──────██░░██──██░░██─██░░██████████─██░░██████░░██─
                        //   ─██░░██████░░██████░░██─██░░██────██░░██──────██░░██──██░░██─██░░██─────────██░░██──██░░██─
                        //   ─██░░██──██░░██──██░░██─██░░████████░░██──────██░░██████░░██─██░░██─────────██░░██████░░██─
                        //   ─██░░██──██░░██──██░░██─██░░░░░░░░░░░░██──────██░░░░░░░░░░██─██░░██──██████─██░░░░░░░░░░██─
                        //   ─██░░██──██████──██░░██─██░░██████░░████──────██░░██████░░██─██░░██──██░░██─██░░██████░░██─
                        //   ─██░░██──────────██░░██─██░░██──██░░██────────██░░██──██░░██─██░░██──██░░██─██░░██──██░░██─
                        //   ─██░░██──────────██░░██─██░░██──██░░██████────██░░██──██░░██─██░░██████░░██─██░░██──██░░██─
                        //   ─██░░██──────────██░░██─██░░██──██░░░░░░██────██░░██──██░░██─██░░░░░░░░░░██─██░░██──██░░██─
                        //   ─██████──────────██████─██████──██████████────██████──██████─██████████████─██████──██████─
                        //   ───────────────────────────────────────────────────────────────────────────────────────────

                        //                                   ⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⢀⣴⣿⣿⠿⣟⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⢸⣏⡏⠀⠀⠀⢣⢻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⢸⣟⠧⠤⠤⠔⠋⠀⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⠀⣿⡆⠀⠀⠀⠀⠀⠸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⠀⠘⣿⡀⢀⣶⠤⠒⠀⢻⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⠀⠀⢹⣧⠀⠀⠀⠀⠀⠈⢿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⠀⠀⠀⣿⡆⠀⠀⠀⠀⠀⠈⢿⣆⣠⣤⣤⣤⣤⣴⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⠀⢀⣾⢿⢿⠀⠀⠀⢀⣀⣀⠘⣿⠋⠁⠀⠙⢇⠀⠀⠙⢿⣦⡀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⢀⣾⢇⡞⠘⣧⠀⢖⡭⠞⢛⡄⠘⣆⠀⠀⠀⠈⢧⠀⠀⠀⠙⢿⣄⠀⠀⠀⠀
                        //                                   ⠀⠀⣠⣿⣛⣥⠤⠤⢿⡄⠀⠀⠈⠉⠀⠀⠹⡄⠀⠀⠀⠈⢧⠀⠀⠀⠈⠻⣦⠀⠀⠀
                        //                                   ⠀⣼⡟⡱⠛⠙⠀⠀⠘⢷⡀⠀⠀⠀⠀⠀⠀⠹⡀⠀⠀⠀⠈⣧⠀⠀⠀⠀⠹⣧⡀⠀
                        //                                   ⢸⡏⢠⠃⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀⠀⠘⣧⠀⠀⠀⠀⠸⣷⡀
                        //                                   ⠸⣧⠘⡇⠀⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀⠀⠀⠀⠀⢣⠀⠀⠀⠀⢹⡇⠀⠀⠀⠀⣿⠇
                        //                                   ⠀⣿⡄⢳⠀⠀⠀⠀⠀⠀⠀⠈⣷⠀⠀⠀⠀⠀⠀⠈⠆⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⠀
                        //                                   ⠀⢹⡇⠘⣇⠀⠀⠀⠀⠀⠀⠰⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⣼⡟⠀⠀
                        //                                   ⠀⢸⡇⠀⢹⡆⠀⠀⠀⠀⠀⠀⠙⠁⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⢳⣼⠟⠀⠀⠀
                        //                                   ⠀⠸⣧⣀⠀⢳⡀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⢃⠀⢀⣴⡿⠁⠀⠀⠀⠀
                        //                                   ⠀⠀⠈⠙⢷⣄⢳⡀⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀⠀⠀⠀⣠⡿⠟⠛⠉⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⠀⠈⠻⢿⣷⣦⣄⣀⣀⣠⣤⠾⠷⣦⣤⣤⡶⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                        //                                   ⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀


