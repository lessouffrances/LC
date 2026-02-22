



class Solution 
{
    public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        // fill the first row
        for (int c=0; c<n; c++) {
            dp[0][c] = matrix[0][c];
        }

        for (int r=1; r<n; r++) {
            for (int c=0; c<n; c++) {
                if (c-1 >= 0 && c+1 < n) {
                    dp[r][c] = matrix[r][c]+min( {dp[r-1][c], dp[r-1][c-1], dp[r-1][c+1]} );
                    continue;
                }
                if (c-1<0) {
                    dp[r][c] = matrix[r][c]+min( {dp[r-1][c], dp[r-1][c+1]} );   
                    continue;
                }
                if (c+1>=n) {
                    dp[r][c] = matrix[r][c]+min( {dp[r-1][c-1], dp[r-1][c]} );   
                    continue;
                }
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};