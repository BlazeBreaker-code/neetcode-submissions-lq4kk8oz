class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        const int n = grid.size();
        const int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cell = grid[i][j];
                maxArea = std::max(maxArea, dfs(grid, i, j));
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1) return 0;
        grid[row][col] = -1; // marked

        return 1 
        + dfs(grid, row - 1, col)
        + dfs(grid, row + 1, col)
        + dfs(grid, row, col - 1)
        + dfs(grid, row, col + 1);
    }
};
