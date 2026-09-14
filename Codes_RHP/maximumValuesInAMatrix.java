import java.util.*;

public class MaximumValuesInAMatrix {
    public static void main (String [] args ) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        // Initialize max with the lowest possible value
        int max = Integer.MIN_VALUE; 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int currentVal = sc.nextInt();
                if (currentVal > max) {
                    max = currentVal;
                }
            }
        }
        System.out.println(max);
    }
}
