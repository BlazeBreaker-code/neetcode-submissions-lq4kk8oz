class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Need 3 lists of unordered sets to check 9 rows, 9 cols, and 9 squares
        vector<std::unordered_set<char>> rows(9);
        vector<std::unordered_set<char>> cols(9);
        vector<std::unordered_set<char>> squares(9);

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[r].size(); ++c) {
                char cell = board[r][c];

                if (cell == '.') continue;

                int sqIdx = (r / 3) * 3 + (c / 3); 
                if (rows[r].contains(cell) || cols[c].contains(cell) || squares[sqIdx].contains(cell)) return false;
                rows[r].insert(cell);
                cols[c].insert(cell);
                squares[sqIdx].insert(cell);
            }
        }

        return true;
    }
};
