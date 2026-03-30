class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        function<bool(int, int, int)> dfs = [&](int row, int col, int i) {
            if (i == word.size()) return true;

            if (row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] != word[i] || board[row][col] == '#') {
                return false;
            }

            board[row][col] = '#';

            bool result = dfs(row + 1, col, i + 1) || 
                          dfs(row - 1, col, i + 1) ||
                          dfs(row, col + 1, i + 1) ||
                          dfs(row, col - 1, i + 1);

            board[row][col] = word[i];
            return result;            
        };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (dfs(row, col, 0)) return true;
            }
        }

        return false;
    }
};
