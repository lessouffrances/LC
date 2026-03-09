
// Children with a higher rating get more candies than their neighbors
// => twoPass

// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    int candy(vector<int>& ratings) 
    {
        if (ratings.empty()) return 0;
        int n = ratings.size();

        vector<int> dp(n, 1);
        // first-pass, compare with the left neighbor
        for (int i=1; i<n; i++) {
            if (ratings[i] > ratings[i-1]) {
                dp[i] = dp[i-1]+1; 
            }
        }

        // second-pass, compare with the right neighbor
        for (int i=n-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                dp[i] = max(dp[i], dp[i+1]+1); // maybe the dp[i] is already > dp[i+1]
            }
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};