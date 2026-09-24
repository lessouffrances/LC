
//      [0,2        ]
// nums = [2,7,9,3,1]

class Solution 
{
    public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i=2; i<n+1; i++) {
            // take
            int take = nums[i-1]+dp[i-2];
            // skip
            int skip = dp[i-1];
            dp[i] = max(take, skip);
        }
        return dp[n];
    }
};