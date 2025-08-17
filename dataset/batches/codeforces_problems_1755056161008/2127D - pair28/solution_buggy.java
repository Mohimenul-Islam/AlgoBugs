import java.util.*;

public class Main {
    static int mod = 1_000_000_007;
    static int[] factorial = new int[200001];
    static HashSet<Integer> visited;
    static int[] order;
    static int[] leaves;

    public static void precompute(){
        factorial[0] = 1;
        for (int i = 1; i < factorial.length; i++) {
            factorial[i] = (int)(((long)factorial[i-1]*i) % mod);
        }
    }

    static class Node {
        int val;
        List<Integer> neig;
        public Node(int v) {
            this.val = v;
            neig = new ArrayList<>();
        }
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        precompute();
        while (t-- > 0) {
            int ans = 0;
            int n = sc.nextInt();
            int m = sc.nextInt();
            HashMap<Integer, List<Integer>> graph = new HashMap<>();
            visited = new HashSet<>();
            leaves = new int[n];
            for (int i = 1; i < n + 1; i++) {
                graph.put(i, new ArrayList<>());
            }
            for (int i = 0; i < m; i++) {
                int n1 = sc.nextInt();
                int n2 = sc.nextInt();
                graph.get(n1).add(n2);
                graph.get(n2).add(n1);
            }

            boolean looped = checkloop(graph, n);
            if (!looped) {
                int sol = findComb(graph, n);
                System.out.println(sol);
            } else {
                System.out.println(0);
            }
        }
    }

    public static int findComb(HashMap<Integer, List<Integer>> graph, int n) {
        long solution = 1;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(1);
        visited.add(1);
        while (!q.isEmpty()) {
            int node = q.poll();
            List<Integer> neig = graph.get(node);
            int countnl = 0, leaf = 0;
            for (int nei : neig) {
                if (visited.contains(nei)) continue;
                visited.add(nei);
                boolean isleaf = checkleaf(graph, nei);
                if (!isleaf) {
                    countnl++;
                    q.add(nei);
                } else {
                    leaf++;
                }
            }
            leaves[node-1] = leaf;
//            solution = (solution *((long)(factorial[Math.max(0,leaf)]) % mod)) % mod;
//            if (countnl > 2) {
//                solution = 0;
//                break;
//            } else if (countnl != 0) {
//                if (leaf + countnl> 1)
//                    solution = (solution*2)%mod;
//            }
        }
        int count = 0;
        for (int l: leaves) {
            if (l != 0) count++;
            solution = (solution * factorial[l]) % mod;
        }
        if (count == 1) solution = 2 * solution;
//        else if (count == 2) solution = 2 * solution;
        else solution = 4 * solution;
//        System.out.println(Arrays.toString(leaves));
        return (int)(solution % mod);
    }

    public static boolean checkleaf(HashMap<Integer, List<Integer>> graph, int l) {
        return graph.get(l).size() == 1;
    }

    public static boolean checkloop(HashMap<Integer, List<Integer>> graph, int n) {
        Queue<Integer> zeroin = new ArrayDeque<>();
        order = new int[n+1];
        int visited = 0;
        for (int i = 1; i < n + 1; i++) {
            List<Integer> neigh = graph.get(i);
            order[i] = neigh.size();
            if (order[i] == 1) {
                zeroin.add(i);
            }
            if (order[i] == 0) visited++;
        }
        HashSet<Integer> hs = new HashSet<>();
        while (!zeroin.isEmpty()) {
            int node = zeroin.poll();
            hs.add(node);
            visited++;
            List<Integer> neigh = graph.get(node);
            for (int nei: neigh) {
                order[nei]--;
                if (order[nei] == 1 && !hs.contains(nei)) zeroin.add(nei);
            }
        }
        return visited != n;
    }
}