import java.util.*;

class Solution {
    private final int[] d = {0, 1, 0, -1, 0};

    public int nearestExit(char[][] maze, int[] e) {
        int R = maze.length;
        int C = maze[0].length;
        Queue<int[]> q = new LinkedList<>();

        q.offer(new int[] {e[0], e[1], 0});
        maze[e[0]][e[1]] = '+';

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int row = curr[0];
            int col = curr[1];
            int steps = curr[2];

            if (row == 0 || row == R - 1 || col == 0 || col == C - 1) {
                if (row != e[0] || col != e[1]) {
                    return steps;
                }
            }

            for (int i = 0; i < 4; i++) {
                int ar = row + d[i];
                int ac = col + d[i + 1];

                if (ar >= 0 && ar < R && ac >= 0 && ac < C && maze[ar][ac] == '.') {
                    maze[ar][ac] = '+';
                    q.offer(new int[] {ar, ac, steps + 1});
                }
            }
        }
        return -1;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        
        int m = scanner.nextInt();
        int n = scanner.nextInt();

        char[][] maze = new char[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maze[i][j] = scanner.next().charAt(0);
            }
        }

        int[] entrance = new int[2];
        entrance[0] = scanner.nextInt();
        entrance[1] = scanner.nextInt();

        Solution solution = new Solution();
        int ans = solution.nearestExit(maze, entrance);

        System.out.println(ans);
    }
}