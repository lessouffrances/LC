// T: O(ROW * COL)
// S: O(1)
class Solution 
{
    public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return;
        int ROW = matrix.size();
        int COL = matrix[0].size();

        // use the first row and first col as markers
        // if we did that, we need to know if the first row/col should be 0
        bool isFirstRowZero = false;
        for (int c=0; c<COL; c++) {
            if (matrix[0][c] == 0) {
                isFirstRowZero = true;
                break;
            }
        }
        bool isFirstColZero = false;
        for (int r=0; r<ROW; r++) {
            if (matrix[r][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // realize the markers
        for (int c=1; c<COL; c++) {
            if (matrix[0][c] == 0) {
                for (int r=1; r<ROW; r++) {
                    matrix[r][c] = 0;
                }
            } 
        }
        for (int r=0; r<ROW; r++) {
            if (matrix[r][0] == 0) {
                for (int c=1; c<COL; c++) {
                    matrix[r][c] = 0;
                }
            } 
        }

        // realize flags
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