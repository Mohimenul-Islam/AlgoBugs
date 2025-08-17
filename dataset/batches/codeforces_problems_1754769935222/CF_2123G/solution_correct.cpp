#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

struct Node {
    long long rem_L, rem_R;
    long long cost;
    long long max_val;
};

Node merge(const Node& left, const Node& right, int g) {
    Node res;
    res.rem_L = left.rem_L;
    res.rem_R = right.rem_R;
    long long middle_cost = (left.rem_R > right.rem_L) ? g : 0;
    res.cost = left.cost + middle_cost + right.cost;
    res.max_val = std::max(left.max_val, left.cost + middle_cost + right.max_val);
    return res;
}

void build(std::vector<Node>& seg_tree, const std::vector<int>& a, int g, int u, int l, int r) {
    if (l == r) {
        long long rem = a[l] % g;
        seg_tree[u] = {rem, rem, 0, rem};
        return;
    }
    int mid = l + (r - l) / 2;
    build(seg_tree, a, g, 2 * u, l, mid);
    build(seg_tree, a, g, 2 * u + 1, mid + 1, r);
    seg_tree[u] = merge(seg_tree[2 * u], seg_tree[2 * u + 1], g);
}

void update(std::vector<Node>& seg_tree, int g, int u, int l, int r, int pos, int new_val) {
    if (l == r) {
        long long rem = new_val % g;
        seg_tree[u] = {rem, rem, 0, rem};
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) {
        update(seg_tree, g, 2 * u, l, mid, pos, new_val);
    } else {
        update(seg_tree, g, 2 * u + 1, mid + 1, r, pos, new_val);
    }
    seg_tree[u] = merge(seg_tree[2 * u], seg_tree[2 * u + 1], g);
}

long long query(const std::vector<Node>& seg_tree) {
    return seg_tree[1].max_val;
}

struct Query {
    int type;
    int p1, p2; // i, x for type 1; k for type 2
};

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> initial_a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> initial_a[i];
    }

    std::vector<Query> queries(q);
    std::map<int, std::vector<int>> g_to_q_indices;

    for (int i = 0; i < q; ++i) {
        std::cin >> queries[i].type;
        if (queries[i].type == 1) {
            std::cin >> queries[i].p1 >> queries[i].p2;
            queries[i].p1--; // 0-indexed
        } else {
            std::cin >> queries[i].p1;
            int g = gcd(queries[i].p1, m);
            g_to_q_indices[g].push_back(i);
        }
    }

    std::vector<bool> answers(q);

    for (auto const& [g, q_indices] : g_to_q_indices) {
        std::vector<Node> seg_tree(4 * n);
        build(seg_tree, initial_a, g, 1, 0, n - 1);
        
        auto it_q2 = q_indices.begin();

        for (int i = 0; i < q; ++i) {
            if (it_q2 != q_indices.end() && *it_q2 == i) {
                answers[i] = (query(seg_tree) < m);
                it_q2++;
            }
            
            if (queries[i].type == 1) {
                update(seg_tree, g, 1, 0, n - 1, queries[i].p1, queries[i].p2);
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        if (queries[i].type == 2) {
            if (answers[i]) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
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