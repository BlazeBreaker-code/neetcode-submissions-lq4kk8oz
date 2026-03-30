class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                int curr = grid[r][c];
                if (curr == 0) dfs(grid, r, c, 0);
            }
        }
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int dist) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return; // Out of bounds
        if (grid[row][col] == -1) return; // Cannot traverse
        if (dist > grid[row][col]) return;

        grid[row][col] = dist;
        
        dfs(grid, row - 1, col, dist + 1);
        dfs(grid, row + 1, col, dist + 1);
        dfs(grid, row, col - 1, dist + 1);
        dfs(grid, row, col + 1, dist + 1);
    }
};
