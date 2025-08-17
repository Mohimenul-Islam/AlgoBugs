#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MOD = 1e9+7;
int t, n, m;
// struct Edge {
//     int u, v;
// };
// Edge edges[200010];
struct Link {
    int x;
    int nxt;
};
Link link[400010];
int head[200010];
// int fa[200010];
int dia[200010]; // diameter
bool visited[200010];
int route[200010];
int route_length, dia_length;
int facto[200010];
int degree[200010];

void init() {
    facto[0] = 1;
    for (int i = 1; i < 200000; i++)
        facto[i] = (long long)facto[i-1] * (long long)i % MOD;
}

inline void add_link(int u, int v, int num) {
    link[num].x = v;
    link[num].nxt = head[u];
    head[u] = num;
}

void dfs(int x) {
    visited[x] = true;
    for (int i = head[x]; i; i = link[i].nxt) {
        int v = link[i].x;
        if (!visited[v]) { // not visited
            dfs(v);
        }
    }
}

bool is_tree() {
    if (n != m + 1) return false;
    memset(visited, false, sizeof(visited));
    dfs(1);
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) return false; // not connected
    }
    return true;
}

void find_longest_path(int x) {
    visited[x] = true;
    for (int i = head[x]; i; i = link[i].nxt) {
        int v = link[i].x;
        if (!visited[v]) {
            route_length += 1;
            route[route_length] = v;
            find_longest_path(v);
            route_length -= 1;
        }
    }
    if (route_length > dia_length) {
        dia_length = route_length;
        memcpy(dia, route, sizeof(int) * (route_length + 1));
    }
}

void find_diameter() {
    route_length = 1;
    route[1] = 1;
    dia_length = 0;
    memset(visited, false, sizeof(visited));
    find_longest_path(1);

    int start = dia[dia_length];
    route_length = 1;
    route[1] = start;
    dia_length = 0;
    memset(visited, false, sizeof(visited));
    find_longest_path(start);
}

int main() {
    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(head, 0, sizeof(head));
        memset(degree, 0, sizeof(degree));
        int u, v;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            add_link(u, v, ++cnt);
            add_link(v, u, ++cnt);
            degree[u]++;
            degree[v]++;
        }
        if (!is_tree()) {
            printf("0\n");
            continue;
        }

        find_diameter();
        // printf("diameter length: %d\n", dia_length);

        int ans = 0;
        if (dia_length == 1) {
            ans = 2;
        } else
        if (dia_length == 2) {
            ans = 2;
        } else
        if (dia_length == 3) {
            ans = (long long)facto[degree[dia[2]]] * 2ll % MOD;
        } else {
            ans = (long long)facto[degree[dia[2]]-1] * (long long)facto[degree[dia[dia_length-1]]-1] % MOD;
            ans = (long long)ans * 4ll % MOD;

            for (int i = 3; i < dia_length - 1; i++) {
                ans = (long long)ans * (long long)facto[degree[dia[i]]-2] % MOD;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}