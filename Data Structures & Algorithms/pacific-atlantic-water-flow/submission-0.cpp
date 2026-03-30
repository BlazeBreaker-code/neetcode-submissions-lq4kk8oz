class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Two oceans on each corner -> water wants to flow between the two and reach each other 
        // Don't think how to get a path from one side to another but instead think can my square reach
        // either sides?

        const int n = heights.size();
        const int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // left and top are pacific
        // right and bottom are atlantic

        for (int r = 0; r < n; ++r) { // left and right
            dfs(heights, r, 0, pacific); // left
            dfs(heights, r, m - 1, atlantic); // right   
        }

        for (int c = 0; c < m; ++c) { // top and bottom
            dfs(heights, 0, c, pacific); // top
            dfs(heights, n - 1, c, atlantic); // bottom 
        }

        vector<vector<int>> ans;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (pacific[r][c] && atlantic[r][c]) ans.push_back({r, c}); // both oceans connect
            }
        }

        return ans;
    }

private: 
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean) {
        const int n = heights.size();
        const int m = heights[0].size();

        ocean[r][c] = true;

        vector<pair<int, int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (ocean[nr][nc]) continue; // already said was true
            if (heights[r][c] > heights[nr][nc]) continue; // we can only traverse if = or less than 

            dfs(heights, nr, nc, ocean);
        }
    }
};
