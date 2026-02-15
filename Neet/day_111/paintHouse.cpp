







class Solution 
{
    public:
    int minCost(vector<vector<int>>& costs) 
    {
        if (costs.empty()) return 0;
        int n = costs.size();
        vector<vector<int>>dp(n, vector<int>(3, 0));

        // base case
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for (int r=1; r<n; r++) {
            dp[r][0] = costs[r][0] + min(dp[r-1][1], dp[r-1][2]);
            dp[r][1] = costs[r][1] + min(dp[r-1][0], dp[r-1][2]);
            dp[r][2] = costs[r][2] + min(dp[r-1][1], dp[r-1][0]);
        }

        return min( {dp[n-1][0], dp[n-1][1], dp[n-1][2]} ); 
    }
};