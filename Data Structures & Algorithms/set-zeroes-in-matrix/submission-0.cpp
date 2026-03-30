class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int n = matrix.size(); 
        const int m = matrix[0].size();

        // update matrix in place O(1) space complexity
        // we can use 0s as markers for what we need to update -> like on the border
        // only issue here is there is a 0 on the border already we need to check for it
        // we will be using the top and left borders so that is what we need to check

        bool firstColZero = false;
        bool firstRowZero = false;

        for (int r = 0; r < n; ++r) {
            if (matrix[r][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        for (int c = 0; c < m; ++c) {
            if (matrix[0][c] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for (int r = 1; r < n; ++r) { // skip first row
            for (int c = 1; c < m; ++c) { // skip first col
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                } 
            }
        }

        for (int r = 1; r < n; ++r) {
            for (int c = 1; c < m; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
            }
        }

        if (firstColZero) {
            for (int r = 0; r < n; ++r) matrix[r][0] = 0; 
        }

        if (firstRowZero) {
            for (int c = 0; c < m; ++c) matrix[0][c] = 0; 
        } 

    }
};
