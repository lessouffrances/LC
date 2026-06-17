
//     ''  a  b  c  d  e
//  ''  0  0  0  0  0  0
//  a   0  1  1  1  1  1
//  c   0  1  1  2  2  2
//  e   0  1  1  2  2  3

// from dp[i][j], up to i-th pos of text2 and j-th pos of text1,
// what is the LCS?

// locally
// if text2[i-1] == text1[j-1]: equals to the val from top-left+1
// if text2[i-1] != text1[j-1], equals max(dp[i-1][j], dp[i][j-1])

class Solution 
{
    public: 
    int longestCommonSubsequence(string text1, string text2) 
    {
        if (text1.length() == 0 && text2.length() == 0) return 0;
        if (text1.length() == 0) return 0;
        if (text2.length() == 0) return 0;

        int ROW = text2.length()+1;
        int COL = text1.length()+1;

        vector<vector<int>> dp(ROW, vector<int>(COL, 0));

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                if (text2[r-1] == text1[c-1]) {
                    dp[r][c] = dp[r-1][c-1]+1;
                } else {
                    dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};