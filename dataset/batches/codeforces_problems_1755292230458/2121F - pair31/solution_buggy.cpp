/*


13 7 2
                      i
-----------------------
0 -1 3 3 3 -2 1 2  2  3  -1  0  3

psum 
-----------------------
0 -1 2 5 8 6  7 9 11 14 13 13 16
                     --
                   0  1


map<int,int> cnt
cnt[x] --> ada berapa banyak prefix sum yang jumlahnya itu x
sejauh ini

sum = 0
for i : 1 to n
    sum += arr[i]
    ans += cnt[sum - s]
*/


/* 

8 3 1
_ _                   l1 l2
_       _              _ _
                               v 
2 2 -1 -2 3 -1 2 2 -5 -1 0 1 1 1
2 4 3   2 5 4  6 8  3  2 2 3 4 5
                               ^ 
      v    v
2 | 1 4 10 11
3 | 3 9 12
4 | 2 6 13
5 | 5 [15]
6 | 7
8 | 8

target = sum-s
       = 5-3
       = 2


kita misalkan tau nilai r
artinya kita mau cari nilai l-1 terjauh sedemikian sehingga
max(a[l],...a[r]) = x
abis kita dapet nilai l1 dan l2 nya
berarti kita tinggal cari banyaknya prefix sum 
diantara index [l1..l2]

kita mau cari maksimum dari [mid+1, mid+2, ... r]
kalo O(N) -> TLE 
kita butuh suatu data struktur buat bisa cari maksimum tapi cepet
di range ini

          
bs1 : cari kemunculan x yang paling kiri
bs2 : cari kemunculan x yang paling kanan

          l1        l2
4 4 4 4 4 3 3 3 3 3 1 1 1 1 

map<int, vector<int>> pos;
pos[x] : index index prefix sum yang jumlahnya adalah x
            l1            l2
            v             v
x | [idx1 idx2 idx3 idx4 idx5]

ans += l2-l1+1
*/

# include <bits/stdc++.h>
using namespace std;
# define int long long 

const int MAXN = 200000;
int node[4*MAXN + 5], arr[MAXN+5];
const int INF = 1e18;
int n;

int merge(int a, int b){
    return max(a, b);
}


void build(int l, int r, int idx){
    if(l == r){
        node[idx] = arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    node[idx] = merge(node[2*idx], node[2*idx+1]);   
}

void update(int pos, int val, int l=1, int r=n, int idx=1){
    if(l == r){
        arr[pos] = val;
        node[idx] = arr[pos];
        return;
    }

    int mid = (l+r)/2;
    if(pos <= mid) update(pos, val, l, mid, 2*idx);
    else update(pos, val, mid+1, r, 2*idx+1);
    node[idx] = merge(node[2*idx], node[2*idx+1]);
}

int get(int from, int to, int l=1, int r=n, int idx=1){
    // no overlap
    if(to < l || from > r){
        return -INF;
    }

    // total overlap
    if(from <= l && r <= to) {
        return node[idx];
    }

    // partial
    int mid = (l+r)/2;
    return merge(
        get(from, to, l, mid, 2*idx),
        get(from, to, mid+1, r, 2*idx+1)
    );
}

int classicSegmentTree(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        update(i, arr[i]);
    }

    int q;
    cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int pos, val;
            cin >> pos >> val;
            update(pos, val);
        }
        else if(t == 2){
            int from, to;
            cin >> from >> to;
            cout << get(from, to) << endl;
        }
    }
    return 0;
}


// kemunculan elemen terkiri yang nilainya x
int binserLeft(vector<int> &pos, int x, int r){
    int lo = 0, hi = (int)pos.size()-1;
    int p = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int maxval = get(pos[mid]+1, r);
        if(maxval <= x){
            if(maxval == x) p = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return p;
}

// kemunculan elemen terkanan yang nilainya x
int binserRight(vector<int> &pos, int x, int r){
    int lo = 0, hi = (int)pos.size()-1;
    int p = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int maxval = get(pos[mid]+1, r);
        if(maxval >= x){
            if(maxval == x) p = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return p;
}

// cari berapa banyak index yang maksimumnya adalah x
int solve(vector<int> &pos, int x, int r){
    int l1 = binserLeft(pos, x, r);
    int l2 = binserRight(pos, x, r);
    // cout << " :: " << r << " : " << l1 << " " << l2 << endl;
    if(l1 != -1 && l2 != -1) return l2-l1+1;
    return 0;
}

void solve(){
    int s, x;
    cin >> n >> s >> x;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    map<int, vector<int>> psum;
    psum[0].push_back(0);
    
    int currsum = 0, ans = 0;
    for(int i=1; i<=n; i++){
        currsum += arr[i];
        int target = currsum - s;
        ans += solve(psum[target], x, i);
        psum[currsum].push_back(i);
    }
    
    cout << ans << endl;

    // cleanup segtree
    for(int i=1; i<=4*n; i++) node[i] = 0;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}