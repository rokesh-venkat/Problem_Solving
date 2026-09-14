import java.util.*;
public class DynamicProgrammingRow {
    static int maxSum = Integer.MIN_VALUE;
    public static void solve(int[][] a, int row, boolean[] used, int sum) {
        int n = a.length;
        if (row == n) {
            maxSum = Math.max(maxSum, sum);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!used[col]) {
                used[col] = true;

                solve(a, row + 1, used, sum + a[row][col]);

                used[col] = false; 
            }}}
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        boolean[] used = new boolean[n];
        solve(a, 0, used, 0);
        System.out.println(maxSum);
    }
}
