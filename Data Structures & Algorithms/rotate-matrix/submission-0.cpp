class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size(); // only need this because we are n x n sq matrix

        for (int r = 0; r < n; ++r) { // swap all diagonals 
            for (int c = r + 1; c < n; ++c) { // we are going to swap along the diagonal
                std::swap(matrix[r][c], matrix[c][r]);
            }
        }

        for (int r = 0; r < n; ++r) { // now we just need to reverse each row
            std::reverse(matrix[r].begin(), matrix[r].end());
        }
    }
};
