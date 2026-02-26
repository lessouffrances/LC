
// A good example to explain the 3 ops:
// ""  c   a   t
// ""  0   1   2   3
// c   1   0   1   2
// u   2   1   1   2
// t   3   2   2   1

class Solution 
{
    public:
    // horse => ros
    int minDistance(string word1, string word2) 
    {
        int ROW = word2.length()+1;
        int COL = word1.length()+1;

        // init dp
        vector<vector<int>>dp(ROW, vector<int>(COL, 0));

        // fill the first row and the first col
        for (int c=0; c<COL; c++) {
            dp[0][c] = c;
        }
        for (int r=0; r<ROW; r++) {
            dp[r][0] = r;
        }

        for (int r=1; r<ROW; r++) {
            for (int c=1; c<COL; c++) {
                // char is already a match
                if (word1[c-1] == word2[r-1]) {
                    dp[r][c] = dp[r-1][c-1];
                    continue;
                }

                // char is not a match, need operations
                dp[r][c] = 1 + min( {dp[r-1][c], dp[r][c-1], dp[r-1][c-1]} ); 
            }
        }
        return dp[ROW-1][COL-1];
    }
};