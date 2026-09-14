#include <iostream>
#include <vector>

class Solution {
private:
    // Direction vectors for moving left, right, up, and down
    const std::vector<std::vector<int>> diff = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void dfs(std::vector<std::vector<char>>& grid, int m, int n, int i, int j) {
        // Sink the current piece of land to prevent infinite loops
        grid[i][j] = '0'; 

        // Explore all 4 neighboring directions
        for (int k = 0; k < 4; ++k) {
            int ar = i + diff[k][0];
            int ac = j + diff[k][1];

            // Check boundaries and if the neighboring cell is land ('1')
            if (ar >= 0 && ar < m && ac >= 0 && ac < n && grid[ar][ac] == '1') {
                dfs(grid, m, n, ar, ac);
            }
        }
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, m, n, i, j);
                    islands++; // Found a new island
                }
            }
        }

        return islands;
    }
};

int main() {
    int m, n;
    std::cout << "Enter number of rows (m) and columns (n): ";
    if (!(std::cin >> m >> n)) return 0;

    std::vector<std::vector<char>> grid(m, std::vector<char>(n));
    std::cout << "Enter the grid values ('1' for land, '0' for water):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grid[i][j];
        }
    }

    Solution solver;
    int result = solver.numIslands(grid);

    std::cout << "\nNumber of islands: " << result << std::endl;

    return 0;
}
