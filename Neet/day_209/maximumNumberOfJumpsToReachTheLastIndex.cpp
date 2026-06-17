class Solution 
{
    public:
    int maximumJumps(vector<int>& nums, int target) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        vector<int>dp(n+1, INT_MIN);
        dp[0] = 0;

        // i < j
        // -target <= nums[j] - nums[i] <= target
        for (int i=0; i<n; i++) {
            if (dp[i] == INT_MIN) continue;
            for (int j=i+1; j<n; j++) {
                if (abs(nums[j]-nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }
        return (dp[n-1] == INT_MIN) ? -1 : dp[n-1];
    }
};