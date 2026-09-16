class Solution 
{
    public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();

        vector<vector<int>> dp(ROW, vector<int>(COL, 0));
        // first row
        int maxEdge = 0;
        for (int c=0; c<COL; c++) {
            if (matrix[0][c] == '0') continue;
            dp[0][c] = 1;
            maxEdge = max(maxEdge, dp[0][c]);
        }
        // first col
        for (int r=0; r<ROW; r++) {
            if (matrix[r][0] == '0') continue;
            dp[r][0] = 1;
            maxEdge = max(maxEdge, dp[r][0]);
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (matrix[r][c] == '0') continue;
                dp[r][c] = min( {dp[r-1][c], dp[r][c-1], dp[r-1][c-1]} ) + 1;
                maxEdge = max(maxEdge, dp[r][c]);
            }
        }
        return maxEdge * maxEdge;
    }
};