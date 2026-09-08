class Solution 
{
    public:
    int candy(vector<int>& ratings) 
    {
        if (ratings.empty()) return 0;
        int n = ratings.size();
        vector<int>dp(n, 1); // at least one 

        // first pass
        for (int i=1; i<n; i++) {
            if (ratings[i] > ratings[i-1]) {
                dp[i] = dp[i-1]+1;
            }
        }
        // second pass
        for (int i=n-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                dp[i] = max(dp[i], dp[i+1]+1);
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};