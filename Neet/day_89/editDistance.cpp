class Solution 
{
    public:
    int minDistance(string word1, string word2) 
    {
        if (word1.empty() || word2.empty()) {
            return (int)(word1.size()+word2.size());
        }

        int ROW = (int)word2.size() + 1;
        int COL = (int)word1.size() + 1;

        vector<vector<int>>dp(ROW, vector<int>(COL, 0));
        for (int r=0; r<ROW; r++) {
            dp[r][0] = r;
        }
        for (int c=0; c<COL; c++) {
            dp[0][c] = c;
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (word1[c-1] == word2[r-1]) {
                    dp[r][c] = dp[r-1][c-1];
                } else {
                    dp[r][c] = 1 + min( {dp[r-1][c], dp[r-1][c-1], dp[r][c-1]} );
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};