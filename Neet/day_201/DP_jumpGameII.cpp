
// nums = [2,3,1,1,4]
// dp   = [0,1,1,2,2]
// subproblem, 
// for each i, what's the minimized steps to get to each i
// dp[0] = 0, base case, don't need any steps to go to 0
// dp = [0,0,0,0,0]
// for each i, find the prev pos that can jump to i, and with the min(dp[prevPos])

class Solution 
{
    public:
    int jump(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i=1; i<n; i++) {
            // look for prev pos that can jump to i
            int minSteps = INT_MAX;
            for (int j=0; j<i; j++) {
                if (j+nums[j] < i) continue;
                minSteps = min(minSteps, dp[j]);
            }
            dp[i] = min(dp[i], minSteps+1);
        }
        return dp[n-1];
    }
};