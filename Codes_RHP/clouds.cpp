#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    const int MAX_R = 2000;
    const int MAX_C = 2000;
    const int GRID_SIZE = 2002;

    vector<int> U(N), D(N), L(N), R(N);
    vector<vector<int>> sky(GRID_SIZE, vector<int>(GRID_SIZE, 0));

    // 1. Difference Array (Imos algorithm) to calculate cloud counts
    for (int i = 0; i < N; i++) {
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        sky[U[i]][L[i]]++;
        sky[U[i]][R[i] + 1]--;
        sky[D[i] + 1][L[i]]--;
        sky[D[i] + 1][R[i] + 1]++;
    }

    // Compute row prefix sum
    for (int r = 1; r <= MAX_R; r++) {
        for (int c = 1; c <= MAX_C; c++) {
            sky[r][c] += sky[r][c - 1];
        }
    }
    // Compute column prefix sum
    for (int r = 1; r <= MAX_R; r++) {
        for (int c = 1; c <= MAX_C; c++) {
            sky[r][c] += sky[r - 1][c];
        }
    }

    // 2. Count initial empty cells (0 clouds) and build prefix sum for single-coverage cells (1 cloud)
    int empty_cells = 0;
    vector<vector<int>> dp(GRID_SIZE, vector<int>(GRID_SIZE, 0));

    for (int r = 1; r <= MAX_R; r++) {
        for (int c = 1; c <= MAX_C; c++) {
            int is_single = (sky[r][c] == 1) ? 1 : 0;
            if (sky[r][c] == 0) {
                empty_cells++;
            }
            dp[r][c] = dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1] + is_single;
        }
    }

    // 3. For each cloud k, answer = empty_cells + (cells covered ONLY by cloud k)
    for (int i = 0; i < N; i++) {
        int u = U[i], d = D[i], l = L[i], r = R[i];
        int single_covered = dp[d][r] - dp[u - 1][r] - dp[d][l - 1] + dp[u - 1][l - 1];
        cout << empty_cells + single_covered << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}