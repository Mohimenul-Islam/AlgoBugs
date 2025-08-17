import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int test = 0; test < t; test++) {
            int n = sc.nextInt();
            long s = sc.nextLong();
            long x = sc.nextLong();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextLong();
            long total_leq = computeTotal(a, s, x, true);
            long total_less = computeTotal(a, s, x, false);
            System.out.println(total_leq - total_less);
        }
        sc.close();
    }

    static long computeTotal(long[] a, long s, long x, boolean isLeq) {
        int n = a.length;
        long total = 0;
        for (int i = 0; i < n; ) {
            if ((isLeq && a[i] > x) || (!isLeq && a[i] >= x)) {
                i++;
                continue;
            }
            int j = i;
            while (j < n && ((isLeq && a[j] <= x) || (!isLeq && a[j] < x))) j++;
            long[] seg = Arrays.copyOfRange(a, i, j);
            total += countSubsum(seg, s);
            i = j;
        }
        return total;
    }

    static long countSubsum(long[] arr, long s) {
        int m = arr.length;
        if (m == 0) return 0;
        long[] prefix = new long[m + 1];
        for (int k = 1; k <= m; k++) {
            prefix[k] = prefix[k - 1] + arr[k - 1];
        }
        Map<Long, Integer> freq = new HashMap<>();
        freq.put(0L, 1);
        long cnt = 0;
        for (int k = 1; k <= m; k++) {
            long needed = prefix[k] - s;
            cnt += freq.getOrDefault(needed, 0);
            freq.put(prefix[k], freq.getOrDefault(prefix[k], 0) + 1);
        }
        return cnt;
    }
}