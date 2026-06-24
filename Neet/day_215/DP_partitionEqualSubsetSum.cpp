class Solution 
{
    public:
    bool canPartition(vector<int>& nums) 
    {
        if (nums.empty()) return false;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (totalSum % 2 == 1) return false;
        int target = totalSum / 2;

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