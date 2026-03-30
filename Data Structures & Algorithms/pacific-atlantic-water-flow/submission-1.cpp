class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int n = heights.size();
        const int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // left and top = pacific
        // right and bottom = atlantic
        for (int r = 0; r < n; ++r) {
            dfs(heights, r, 0, pacific);
            dfs(heights, r, m - 1, atlantic);
        }

        for (int c = 0; c < m; ++c) {
            dfs(heights, 0, c, pacific);
            dfs(heights, n - 1, c, atlantic);
        }

        vector<vector<int>> ans;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (pacific[r][c] && atlantic[r][c]) ans.push_back({r, c});
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;

        const int n = heights.size();
        const int m = heights[0].size();

        vector<pair<int, int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue; // out of bounds
            if (ocean[nr][nc]) continue; // already true and visited
            if (heights[r][c] > heights[nr][nc]) continue; // not equal or lesser height land
            
            dfs(heights, nr, nc, ocean);
        }
    }
};
