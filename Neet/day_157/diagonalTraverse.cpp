



class Solution 
{
    public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {       
        vector<int> res;
        int ROW = mat.size();
        int COL = mat[0].size();

        int row = 0, col = 0;
        for (int i=0; i<ROW*COL; i++) {
            res.push_back(mat[row][col]);

            if ((row+col) % 2 == 0) {
                // go up-right 
    
                if (col == COL-1) {
                    row++;
                } else if (row == 0) {
                    col++;
                } else {
                    row--;
                    col++;
                }

            } else {
                // go down-left
                if (row == ROW-1) {
                    col++;
                } else if (col == 0) {
                    row++;
                } else {
                    row++;
                    col--;
                }
            }
        } 

        return res;
    }
};