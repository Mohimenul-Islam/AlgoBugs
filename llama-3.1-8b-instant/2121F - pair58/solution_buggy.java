import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while (t-- > 0) {
            int n = sc.nextInt();
            long s = sc.nextLong();
            int x = sc.nextInt();
            
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            
            int count = 0;
            
            // Try all possible left boundaries
            for (int l = 0; l < n; l++) {
                long currentSum = 0;
                int currentMax = Integer.MIN_VALUE;
                
                // Try all possible right boundaries starting from l
                for (int r = l; r < n; r++) {
                    currentSum += a[r];
                    currentMax = Math.max(currentMax, a[r]);
                    
                    // Check if both conditions are satisfied
                    if (currentSum == s && currentMax == x) {
                        count++;
                    }
                }
            }
            
            System.out.println(count);
        }
        
        sc.close();
    }
}