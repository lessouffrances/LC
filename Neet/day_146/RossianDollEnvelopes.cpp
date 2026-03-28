

// Time: O(N^2)
// Space: O(N)

class Solution 
{
    public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        if (envelopes.empty()) return 0;

        int n = envelopes.size();
        if (n == 0) return 0;

        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n+1, 1);
        int max = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (envelopes[i][0] > envelopes[j][0]
                && envelopes[i][1] > envelopes[j][1]
                && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;
                }

                max = max(max, dp[i]);
            }
        }
        return max;
    } 
};