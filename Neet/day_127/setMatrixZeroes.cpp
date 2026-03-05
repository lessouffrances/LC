class Solution 
{
    public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        // check if first row and col should be zeroes
        for (int c=0; c<COL; c++) {
            if (matrix[0][c] == 0) isFirstRowZero = true;
        }
        for (int r=0; r<ROW; r++) {
            if (matrix[r][0] == 0) isFirstColZero = true;
        }

        // use first row and col as markers to mark rows and cols that should be zeroes
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        // reconciliate with markers and set 0
        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) matrix[r][c] = 0;
            }
        }

        // set 0 for first row and first col
        if (isFirstRowZero) {
            for (int c=0; c<COL; c++) {
                matrix[0][c] = 0;
            }
        } 

        if (isFirstColZero) {
            for (int r=0; r<ROW; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};