//       {2, 7, 9, 3, 1}
// {0  0  2  0  0  0  0}

class Solution
{
    public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int>dp(n+2, 0);
        // base case
        dp[2] = nums[0];

        for (int i=3; i<n+2; i++) {
            // skip 
            int skip = dp[i-1];

            // take
            int take = nums[i-2] + dp[i-2];

            dp[i] = max(skip, take);

        }
        return dp[n+1];
    }
};