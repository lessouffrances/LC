class Solution 
{
    public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        if (mat.empty()) return {};

        int ROW = mat.size();
        int COL = mat[0].size();

        vector<int> res;
        int row = 0, col = 0;

        for (int i=0; i<ROW*COL; i++) {
            res.push_back(mat[row][col]);

            // if sum of coords is even, go up right
            if ((row+col) % 2 == 0) {
                if (col == COL-1) {
                    row++;
                } else if (row == 0) {
                    col++;
                } else {
                    row--;
                    col++;
                }

            } else {
                if (row == ROW-1) {
                    col++;
                } else if (col == 0) {
                    row++;
                } else {
                    col--;
                    row++;
                }
            }
        }
        return res;
    }
};