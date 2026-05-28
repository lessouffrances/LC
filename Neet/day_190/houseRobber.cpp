

// nums = [2,7,9,3,1]
//   [0,0,0,0,0,0,0]
// 12

// Time: O(N)
// Space: O(N)
class Solution 
{
    public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> dp(n+2, 0);

        for (int i=2; i<n+2; i++) {
            int take = dp[i-2] + nums[i];
            int skip = dp[i-1];

            dp[i] = max(take, skip);
        }
        return dp[n+1];
    }
};