#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

const int MOD = 1e9 + 7;

struct Mint {
    long long val;

    Mint(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    Mint operator+(const Mint& other) const { return Mint(val + other.val); }
    Mint operator-(const Mint& other) const { return Mint(val - other.val); }
    Mint operator*(const Mint& other) const { return Mint(val * other.val); }
    
    Mint power(long long p) const {
        Mint res = 1;
        Mint base = *this;
        while (p > 0) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }

    Mint inv() const {
        return power(MOD - 2);
    }

    Mint operator/(const Mint& other) const { return *this * other.inv(); }

    Mint& operator+=(const Mint& other) { *this = *this + other; return *this; }
    Mint& operator-=(const Mint& other) { *this = *this - other; return *this; }
    Mint& operator*=(const Mint& other) { *this = *this * other; return *this; }
    Mint& operator/=(const Mint& other) { *this = *this / other; return *this; }

    bool operator==(const Mint& other) const { return val == other.val; }
    bool operator!=(const Mint& other) const { return val != other.val; }

    friend std::istream& operator>>(std::istream& is, Mint& m) {
        long long v;
        is >> v;
        m = Mint(v);
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Mint& m) {
        return os << m.val;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n + 1);
    
    Mint ans = 2; 

    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    if (m != n - 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::function<int(int, int, int)> dfs;
    dfs = [&](int cur, int fa, int s) -> int {
        int ch_num = 0; 
        int non_leaf_children_count = 0; 

        for (int neighbor : v[cur]) {
            if (neighbor == fa) continue;
            
            ch_num++;
            non_leaf_children_count += dfs(neighbor, cur, 1);
        }

        if (ch_num == 0) {
            return 0; 
        }
            
        if (non_leaf_children_count > s) {
            ans = 0;
            return 1; 
        }

        Mint p_s_nl = 1;
        for (int i = 0; i < non_leaf_children_count; ++i) {
            p_s_nl *= (s - i);
        }
        ans *= p_s_nl;

        for (int i = 1; i <= ch_num - non_leaf_children_count; ++i) {
            ans *= i;
        }
        
        return 1; 
    };

    if (n == 2) {
        int idx = 1;
        dfs(idx, idx, 2);
    } else {
        int idx = 0;
        for (int i = 1; i <= n; ++i) {
            if (v[i].size() > 1) {
                idx = i;
                break;
            }
        }
        dfs(idx, idx, 2);
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}