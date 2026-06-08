class Solution 
{
    public:
    int maximumJumps(vector<int>& nums, int target) 
    {
        if (nums.empty()) return -1;
        int n = nums.size();

        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        // subproblem: maximum jumps required to jump from 0 to i

        for (int i=0; i<n; i++) {
            if (dp[i] == INT_MIN) continue;  
            for (int j=i+1; j<n; j++) {
                if (abs(nums[j]-nums[i]) <= target) {
                    dp[j] = max(dp[j], 1+dp[i]);
                }
            }
        }

        return dp[n-1] == INT_MIN ? -1 : dp[n-1];
    }
};