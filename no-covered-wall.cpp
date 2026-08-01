import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner scanner= new Scanner(System.in);
    int N = scanner.nextInt();
    int M = scanner.nextInt();

    // Difference array to manage range updates efficiently
    int[] result = new int[N + 2];
    
    while(M-- >0){
      int L= scanner.nextInt();
      int R = scanner.nextInt();
      result[L]++;
      result[R+1]--;
    }
   // Calculate prefix sum to get the count of turrets for each castle wall
   int currentTurrets = 0;
   int minTurrets = Integer.MAX_VALUE;
        for (int i = 1; i <= N; i++) {
            currentTurrets += result[i];
            if (currentTurrets < minTurrets) {
                minTurrets = currentTurrets;
            }
        }

        System.out.println(minTurrets);
  }
}