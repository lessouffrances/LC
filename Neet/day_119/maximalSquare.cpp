



class Solution 
{
    public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;
        int ROW = matrix.size();
        int COL = matrix[0].size();

        vector<vector<int>> dp(ROW, vector<int>(COL, 0));
        int maxEdge = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                dp[r][c] = matrix[r][c]-'0';
                maxEdge = max(maxEdge, dp[r][c]);
            }
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (matrix[r][c] == '0') continue;

                if (dp[r-1][c]>0 && dp[r-1][c-1]>0 && dp[r][c-1]>0) {
                    dp[r][c] = min( {dp[r-1][c-1], dp[r-1][c], dp[r][c-1]} )+1;
                    maxEdge = max(maxEdge, dp[r][c]);
                }
            }
        }

        return maxEdge * maxEdge;
    }
};