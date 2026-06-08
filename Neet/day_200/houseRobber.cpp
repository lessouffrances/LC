


// subproblem: for all the houses [0....i], what's the maximized value?
// for each house i, there are two options:
//   1) take: value_i + dp[i-2]
//   2) skip: dp[i-1]
//   3) max(take, skip)

// nums =   [2,7,9,3,1]
// dp = [0,0,0,0,0,0,0]   

class Solution 
{
    public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n+2, 0);

        // iterate thru the dp
        for (int i=2; i<n+2; i++) {
            int take = nums[i-2]+dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(take, skip);
        }
        return dp[n+1];
    }
};