class Solution 
{
    public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int i=0; i<n; i++) {
            for (int currAmt=target; currAmt>=nums[i]; currAmt--) {
                if (dp[currAmt-nums[i]]) {
                    dp[currAmt] = true;
                }
            }
        }
        return dp[target];
    }
};