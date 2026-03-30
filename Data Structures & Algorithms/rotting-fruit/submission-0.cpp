class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // return the min number of time it would take for all the fruits to be rotten
        const int n = grid.size();
        const int m = grid[0].size();

        std::queue<pair<int, int>> q; // {row, col} so we call call BFS on all

        int fresh = 0;
        int minutes = 0;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) ++fresh;
            }
        }

        std::vector<pair<int, int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        while (!q.empty() && fresh > 0) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto [r, c] = q.front(); q.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue; // out of bounds
                    if (grid[nr][nc] != 1) continue; // not a fresh fruit

                    grid[nr][nc] = 2;
                    --fresh;
                    q.push({nr, nc});
                }
            }

            ++minutes;
        }

        return (fresh == 0) ? minutes : -1; 
    }
};
