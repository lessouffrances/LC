




class Solution 
{
    public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        // contains how many ways we can make up dp[i]
        vector<unsigned long long>dp(target+1, 0);

        // base case
        dp[0] = 1;

        // this essentially counts permutations of combinations
        for (int amount=1; amount<=target; amount++) {
            for (int num : nums) {
                if (num <= amount) {
                    dp[amount] += dp[amount-num];
                }
            }
        }
        return dp[target];
    }
};