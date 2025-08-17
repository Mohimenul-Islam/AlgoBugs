import java.io.*;
import java.util.*;

public class main2 {
    static final int MOD = (int)1e9 + 7;
    static final int MXN = (int)2e5 + 5;
    static int n, m;
    static int[] fact = new int[MXN];
    static ArrayList<Integer>[] adj = new ArrayList[MXN];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        // Precompute factorials
        fact[0] = 1;
        for (int i = 1; i < MXN; i++) {
            fact[i] = (int)((1L * fact[i - 1] * i) % MOD);
        }

        // Initialize adjacency list
        for (int i = 0; i < MXN; i++) {
            adj[i] = new ArrayList<>();
        }

        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] parts = br.readLine().trim().split(" ");
            n = Integer.parseInt(parts[0]);
            m = Integer.parseInt(parts[1]);

            for (int i = 1; i <= n; i++) {
                adj[i].clear();
            }

            for (int i = 0; i < m; i++) {
                String[] uv = br.readLine().trim().split(" ");
                int u = Integer.parseInt(uv[0]);
                int v = Integer.parseInt(uv[1]);
                adj[u].add(v);
                adj[v].add(u);
            }

            long ans = 2;
            int tl = 0;
            if (m >= n) ans = 0;

            for (int u = 1; u <= n; u++) {
                if (adj[u].size() > 1) {
                    int x = 0;
                    for (int v : adj[u]) {
                        if (adj[v].size() == 1) {
                            x++;
                        }
                    }
                    if (x >= adj[u].size() - 2) {
                        ans = (ans * fact[x]) % MOD;
                    } else {
                        ans = 0;
                    }
                } else {
                    tl++;
                }
            }

            if (tl < n - 1) tl = 2;
            else tl = 1;

            out.append((ans * tl) % MOD).append("\n");
        }

        System.out.print(out);
    }
}
