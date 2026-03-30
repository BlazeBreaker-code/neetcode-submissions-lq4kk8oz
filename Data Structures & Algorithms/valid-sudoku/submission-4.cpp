class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<std::unordered_set<char>> rows(9);
        vector<std::unordered_set<char>> cols(9);
        vector<std::unordered_set<char>> squares(9);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                char cell = board[i][j];
                if (cell == '.') continue;

                int squareIdx = (i / 3) * 3 + (j / 3);// there are 9 squares
                if (rows[i].contains(cell) || cols[j].contains(cell) || squares[squareIdx].contains(cell)) return false;
                rows[i].insert(cell);
                cols[j].insert(cell);
                squares[squareIdx].insert(cell);
            }
        }

        return true;
    }
};
