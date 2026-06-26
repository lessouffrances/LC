class Solution 
{
    public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        // the goal is to reach cost.size()
        int n = cost.size();
        vector<int>dp(n+1, 0); // means the minimum cost to reach this pos
        // base case:

        for (int pos=2; pos<n+1; pos++) {
            // option one jump from pos-1
            int option1 = dp[pos-1]+cost[pos-1];
            int option2 = dp[pos-2]+cost[pos-2];
            dp[pos] = min(option1, option2);
        }
        return dp[n];
    }
};