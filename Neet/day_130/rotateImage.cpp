class Solution 
{
    public:
    void rotate(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return;
        int ROW = matrix.size();
        int COL = matrix[0].size();

        // do the matrix transpose
        for (int r=0; r<ROW; r++) {
            for (int c=r+1; c<COL; c++) {
                if (r != c) {
                    int temp = matrix[r][c];
                    matrix[r][c] = matrix[c][r];
                    matrix[c][r] = temp;
                }
            }
        }

        // reverse each row
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};