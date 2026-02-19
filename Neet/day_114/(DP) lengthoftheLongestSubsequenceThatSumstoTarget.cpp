class Solution 
{
    public:
        int lengthOfLongestSubsequence(vector<int>& nums, int target) 
        {
            if (nums.empty()) return 0;

            vector<int>dp(target+1, -1);
            dp[0] = 0;

            for (int num : nums) {
                for (int sum=target; sum>=num; sum--) {
                    if (dp[sum - num] != -1) {
                        dp[sum] = max(dp[sum], dp[sum - num] + 1);
                    }
                }
            }
            return dp[target];
        }
    };