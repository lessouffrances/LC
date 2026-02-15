





class Solution 
{
    public:
    int candy(vector<int>& ratings) 
    {
        if (ratings.empty()) return 0;
        int n = ratings.size();

        vector<int>dp(n, 1);

        // left to right pass
        for (int i=1; i<n; i++) {
            if (ratings[i] > ratings[i-1]) {
                dp[i] = dp[i-1]+1;
            }
        }

        // right to left pass
        for (int i=n-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                dp[i] = max(dp[i], dp[i+1]+1);
            }
        }

        // return
        int total = accumulate(dp.begin(), dp.end(), 0);
        return total;
    }
};