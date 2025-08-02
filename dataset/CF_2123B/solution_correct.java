import java.io.*;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer in = new StreamTokenizer(br);
        PrintWriter out = new PrintWriter(System.out);
        in.nextToken();
        int t = (int) in.nval;
        while (t-- > 0) {
            in.nextToken(); int n = (int) in.nval;
            in.nextToken(); int j = (int) in.nval;
            in.nextToken(); int k = (int) in.nval;
            int[] a = new int[n];
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                in.nextToken(); a[i] = (int) in.nval;
                if (max < a[i]) {
                    max = a[i];
                }
            }
            int x = a[j - 1];
            boolean ans = true;
            if (k == 1 && x < max) {
                ans = false;
            }
            out.println(ans ? "yes" : "no");
        }
        out.close();
        out.close();
        br.close();
    }
}
