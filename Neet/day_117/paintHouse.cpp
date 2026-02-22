class Solution 
{
    public:
    int minCost(vector<vector<int>>& costs) 
    {
        if (costs.empty()) return 0;

        int n = costs.size();
        vector<vector<int>>dp(n, vector<int>(3, 0));

        // fill the first row
        for (int c=0; c<3; c++) {
            dp[0][c] = costs[0][c];
        }

        for (int r=1; r<n; r++) {
            for (int c=0; c<3; c++) {
                int prevChoice = INT_MAX;
                for (int j=0; j<3; j++) {
                    if (j == c) continue;
                    prevChoice = min(prevChoice, dp[r-1][j]);
                }
                dp[r][c] = costs[r][c] + prevChoice;
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};