// text1 = "abcde", 
// text2 = "ace" 

//      ''  a b c d e
//  ''   0  0 0 0 0 0
//  a    0  1 1 1 1 1
//  c    0  1 1 2 2 2
//  e    0  1 1 2 2 3

// dp[i][j], up until text1[i-1] and text2[j-1], what is the LCS?
// recursion
// if text1[i-1] == text2[j-1]:
// dp[i][j] = dp[i-1][j-1] + 1
// else:
// dp[i][j] = max(dp[i-1][j], dp[i][j-1])

class Solution 
{
    public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int COL = text1.length()+1;
        int ROW = text2.length()+1;

        vector<vector<int>> dp(ROW, vector<int>(COL, 0));

        for (int r=1; r<ROW; r++) { 
            for (int c=1; c<COL; c++) {
                if (text1[c-1] == text2[r-1]) {
                    dp[r][c] = dp[r-1][c-1] + 1;
                } else {
                    dp[r][c] = max( {dp[r-1][c], dp[r][c-1]} );
                }
            }
        }
        return dp[ROW-1][COL-1];
    }
};