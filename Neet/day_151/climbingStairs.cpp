



// Time: O (N)
// Space: O (N)

// recurrence analysis
// subproblem:
// how many ways can we reach to each staircase?
// n = 4
// 0->1->2->3->4
// 1  1  2  3  5
class Solution 
{
    public:
    int climbStairs(int n) 
    {
        if (n == 0 || n == 1) return 1;
        vector<int> dp(n+1, 0);

        // base cases
        dp[0] = 1;
        dp[1] = 1;

        for (int i=2; i<n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};