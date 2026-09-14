import java.util.HashMap;
import java.util.Scanner;

public class Main {
    
    public static int findTheLongestBalancedSubstring(String s) {
        // Map to store the first occurrence of a prefix sum: <Sum, Index>
        HashMap<Integer, Integer> map = new HashMap<>();
        
        // Base case: A sum of 0 effectively occurs at index -1
        map.put(0, -1);
        
        int maxLen = 0;
        int runningSum = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Treat '0' as -1 and '1' as +1
            if (s.charAt(i) == '0') {
                runningSum += -1;
            } else {
                runningSum += 1;
            }
            
            // If this sum has been seen before, calculate the length of the substring
            if (map.containsKey(runningSum)) {
                int previousIndex = map.get(runningSum);
                maxLen = Math.max(maxLen, i - previousIndex);
            } else {
                // Otherwise, store the first time we see this sum
                map.put(runningSum, i);
            }
        }
        
        return maxLen;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        
        System.out.print("Enter a binary string (containing only 0s and 1s): ");
        
        // Read user input
        String userInput = scanner.nextLine();
        
        // Optional validation to ensure input only contains 0 and 1
        if (!userInput.matches("[01]*")) {
            System.out.println("Error: Please enter a valid binary string containing only '0' and '1'.");
        } else {
            // Calculate and display the result
            int result = findTheLongestBalancedSubstring(userInput);
            System.out.println("The length of the longest substring with equal 0s and 1s is: " + result);
        }
        
        scanner.close();
    }
}
