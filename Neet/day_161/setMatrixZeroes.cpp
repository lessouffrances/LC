

// Time: O(ROW * COL)
// Space: O(ROW * COL)
class Solution 
{
    public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        // because we'll use the first row and last row as markers 
        // let's see if they should be 0 first
        bool isFirstRowZero = false, isFirstColZero = false;
        for (int c=0; c<COL; c++) {
            if (matrix[0][c] == 0) isFirstRowZero = true;
        }
        for (int r=0; r<ROW; r++) {
            if (matrix[r][0] == 0) isFirstColZero = true;
        }

        // now iterate the rest of the matrix
        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (matrix[r][c] == 0) {
                    // marker will be 0
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        // realize the marker
        for (int c=1; c<COL; c++) {
            if (matrix[0][c] == 0) {
                for (int r=0; r<ROW; r++) {
                    matrix[r][c] = 0;
                }
            }
        }
        for (int r=1; r<ROW; r++) {
            if (matrix[r][0] == 0) {
                for (int c=0; c<COL; c++) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (isFirstColZero) {
            for (int r=0; r<ROW; r++) {
                matrix[r][0] = 0;
            }
        }
        if (isFirstRowZero) {
            for (int c=0; c<COL; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};