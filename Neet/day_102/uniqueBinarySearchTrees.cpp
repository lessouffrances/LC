










class Solution 
{
    public:
    int numTrees(int n) 
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int nodes=2; nodes<=n; nodes++) { // how many nodes in total
            for (int root=1; root<=nodes; root++) { // which one is the root
                dp[nodes] += dp[root-1]*dp[nodes-root];
            }
        }
        return dp[n];
    }
};