import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // 1. Read dimensions and initialize the grid
        int R = sc.nextInt(), C = sc.nextInt();
        int grid[][] = new int[R][C];
        
        // 2. Populate the grid with user input
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                grid[row][col] = sc.nextInt();
            }
        }
        
        // 3. Read the target cell coordinates
        int row = sc.nextInt(), col = sc.nextInt();
        
        // 4. Define coordinate offsets for all 8 directions
        final int diff[][] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        long sum = 0; // Declaring the missing sum variable
        
        // 5. Traverse all 8 neighbors
        for (int i = 0; i < 8; i++) {
            int adjRow = row + diff[i][0];
            int adjCol = col + diff[i][1];
            
            // Boundary check: Ensure neighbor is inside the grid matrix
            if (adjRow >= 0 && adjRow < R && adjCol >= 0 && adjCol < C) {
                sum += grid[adjRow][adjCol];
            }
        }
        
        // 6. Print the final calculated sum
        System.out.println(sum);
    }
}
