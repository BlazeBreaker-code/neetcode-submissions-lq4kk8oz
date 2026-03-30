class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // The way to think about these type of questions is ask the opposite side of it
        // Capture all the surrounded regions ->
        // Capture everything except the unsurrounded regions = anything touching the border
        const int n = board.size();
        const int m = board[0].size();

        // Run dfs and mark all the nodes that don't need to be captured
        for (int r = 0; r < n; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0); 
            if (board[r][m - 1] == 'O') dfs(board, r, m - 1);
        }

        for (int c = 0; c < m; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c); 
            if (board[n - 1][c] == 'O') dfs(board, n - 1, c);
        }

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == 'M') board[r][c] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        board[r][c] = 'M';

        const int n = board.size();
        const int m = board[0].size();

        const vector<pair<int, int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (board[nr][nc] != 'O') continue;

            dfs(board, nr, nc);
        }
    }
};
