class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // we just need to check surrounding waters if we hit an island
        int islands = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                char c = grid[i][j];
                if (c == '1') {
                    dfs(grid, i, j);
                    ++islands;
                }
            }
        }

        return islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '#';

        if (row - 1 >= 0 && grid[row - 1][col] == '1')              dfs(grid, row - 1, col);
        if (row + 1 < grid.size() && grid[row + 1][col] == '1')     dfs(grid, row + 1, col);
        if (col - 1 >= 0 && grid[row][col - 1] == '1')              dfs(grid, row, col - 1);
        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1')  dfs(grid, row, col + 1);
    }
};
