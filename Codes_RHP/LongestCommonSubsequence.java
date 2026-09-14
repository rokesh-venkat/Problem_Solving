import java.util.Scanner;

public class LongestCommonSubsequence {

    /**
     * Finds the length of the longest common subsequence between two strings.
     * * @param S1 First string
     * @param S2 Second string
     * @return The length of the longest common subsequence
     */
    public static int longestCommonSubsequence(String S1, String S2) {
        if (S1 == null || S2 == null || S1.isEmpty() || S2.isEmpty()) {
            return 0;
        }

        int m = S1.length();
        int n = S2.length();

        // dp[i][j] stores the LCS length of S1[0...i-1] and S2[0...j-1]
        int[][] dp = new int[m + 1][n + 1];

        // Build the DP table bottom-up
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (S1.charAt(i - 1) == S2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    public static void main(String[] args) {
        // Initialize Scanner to read input from the console
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the first string: ");
        String S1 = input.nextLine();

        System.out.print("Enter the second string: ");
        String S2 = input.nextLine();

        // Calculate and display the result
        int length = longestCommonSubsequence(S1, S2);
        System.out.println("Length of Longest Common Subsequence: " + length);

        // Close the scanner resource
        input.close();
    }
}
