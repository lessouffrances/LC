class Solution 
{
    public:
    bool canJump(vector<int>& nums) 
    {
        if (nums.empty()) return false;

        int n = nums.size();
        vector<bool>dp(n, false);
        dp[n-1] = true;

        for (int i=n-2; i>=0; i--) {
            if (nums[i] == 0) dp[i] = false;
            
            int dist = (n-1) - i;
            if (nums[i] >= dist) {
                dp[i] = true;
                continue;
            } 

            bool found = false;
            for (int j=i+1; j<=i+nums[i]; j++) {
                if (dp[j] == true) {
                    dp[i] = true;
                    found = true;
                    break;
                }
            }
            if (found) continue;

            dp[i] = false;
        }

        return dp[0];
    }
};