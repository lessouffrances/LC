class Solution 
{
    public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1, INT_MAX); 
        // contains the least number of perfect-squared numbers sum to i
        dp[0] = 0;

        for (int sum=1; sum<=n; sum++) {
            for (int num=1; num*num <= sum; num++) {
                dp[sum] = min(dp[sum], dp[sum - num*num] + 1);
            }
        }
        return dp[n];
    }
};