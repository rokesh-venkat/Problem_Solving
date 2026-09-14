public class LongestCommonSubstring {

    /**
     * Finds the length of the longest common substring between two strings.
     * * @param S1 First string
     * @param S2 Second string
     * @return The length of the longest common substring
     */
    public static int longestCommonSubstring(String S1, String S2) {
        if (S1 == null || S2 == null || S1.isEmpty() || S2.isEmpty()) {
            return 0;
        }

        int m = S1.length();
        int n = S2.length();
        
        // dp[i][j] stores the length of the longest common suffix 
        // of substrings S1[0...i-1] and S2[0...j-1]
        int[][] dp = new int[m + 1][n + 1];
        int maxLength = 0; // To store the maximum length found

        // Build the DP table from bottom up
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, extend the common suffix length from the previous diagonal
                if (S1.charAt(i - 1) == S2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = Math.max(maxLength, dp[i][j]);
                } else {
                    // If they don't match, the sequence breaks, reset suffix length to 0
                    dp[i][j] = 0;
                }
            }
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String S1 = input.nextLine();
        String S2 = input.nextLine();

        int length = longestCommonSubstring(S1, S2);
        System.out.println("Length of Longest Common Substring: " + length); 
        // Output: 4 (The substring is "CDGH")
        input.close();
    }
}
