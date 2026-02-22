class Solution 
{
    public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<unsigned long long>dp(target+1, 0);
        // the dp contains: how many ways can make up this number

        // base case
        dp[0] = 1;

        for (int amount=1; amount<=target; amount++) {
            for (int num : nums) {
                if (num <= amount) {
                    dp[amount] += dp[amount - num];
                }
            }
        }

        return dp[target];
    }
};