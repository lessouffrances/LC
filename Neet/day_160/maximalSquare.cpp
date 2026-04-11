

// Time: O(ROW * COL)
// Space: O(ROW * COL)

class Solution 
{
    public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;
        int ROW = matrix.size();
        int COL = matrix[0].size();

        // init a dp that of the same dimensions as the matrix
        vector<vector<int>> dp = vector(ROW, vector<int>(COL, 0));

        // treat each square as the top-left corner of the possible square
        // fill the first row and first col

        int maxEdge = 0;

        for (int c=0; c<COL; c++) {
            if (matrix[0][c] == '1') {
                dp[0][c] = 1;
                maxEdge = 1;
            }
        }
        for (int r=0; r<ROW; r++) {
            if (matrix[r][0] == '1') {
                dp[r][0] = 1;
                maxEdge = 1;
            }
        }

        // check the rest of the cells

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (matrix[r][c] == '0') continue;

                if (dp[r-1][c] >= 1 && dp[r][c-1] >= 1) {
                    dp[r][c] = min( {dp[r-1][c-1], dp[r-1][c], dp[r][c-1]} ) + 1;
                    
                } else {
                    dp[r][c] = 1;
                }
                maxEdge =  max(maxEdge, dp[r][c]);
            }
        }
        return maxEdge * maxEdge;
    }
};