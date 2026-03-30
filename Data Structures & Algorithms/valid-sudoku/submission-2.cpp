class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> squares[9];

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                int sqIdx = (i / 3) * 3 + (j / 3);
                if (rows[i].count(c) || cols[j].count(c) || squares[sqIdx].count(c)) return false;
                rows[i].insert(c);
                cols[j].insert(c);
                squares[sqIdx].insert(c);
            }
        }

        return true;
    }
};
