class Solution 
{
    public:
    bool canPartition(vector<int>& nums) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        vector<bool>dp(target+1, false);
        dp[0] = true;
        for (int i=0; i<n; i++) {
            for (int currAmt=target; currAmt>=nums[i]; currAmt--) {
                if (dp[currAmt-nums[i]] != false) {
                    dp[currAmt] = true;
                }
            }
        }
        return dp[target];
    }
};