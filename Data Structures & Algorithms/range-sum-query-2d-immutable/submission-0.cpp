class NumMatrix {
    // Given a matrix -> return the sum of the elements from the top left to the
    // bottom right
    // We want to iterate once duing the solution so maybe a prefix sum matrix?
    // then the total is the sum = sum after - sum before 
    
private: 
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        prefix = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                prefix[r + 1][c + 1] =
                    matrix[r][c]
                    + prefix[r][c + 1]
                    + prefix[r + 1][c]
                    - prefix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1]
               - prefix[row1][col2 + 1]
               - prefix[row2 + 1][col1]
               + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */