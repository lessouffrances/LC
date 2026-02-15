class Solution 
{
    public:
    bool canPartition(vector<int> &nums) 
    {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) return false;
        int amount = totalSum / 2;
        int n = nums.size();

        vector<bool>dp(amount+1, false);
        dp[0] = true;

        for (int j=0; j<n; j++) {
            for (int currAmt=amount; currAmt>=nums[j]; currAmt--) {
                if (dp[currAmt-nums[j]]) {
                    dp[currAmt] = true;
                };
            }
        }
        return dp[amount];
    }
};
