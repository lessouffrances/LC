class Solution 
{
    public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        for (int r=0; r<ROW; r++) {
            for (int c=r+1; c<COL; c++) {
                if (r != c) {
                    swap(matrix[r][c], matrix[c][r]);
                }
            }
        }

        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};