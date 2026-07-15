class Solution 
{
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        if (days.empty()) return 0;

        unordered_set<int> travelDays(days.begin(), days.end());
        int lastDay = *max_element(days.begin(), days.end());

        vector<int>dp(lastDay+1, 0);
        // base case: dp[0] = 0
        // subproblem:
        // dp[i] answers that, what is the min costs up until day[i]

        for (int i=1; i<dp.size(); i++) {
            if (!travelDays.count(i)) {
                // if today is not a travel day,
                // do not incur any expenses
                dp[i] = dp[i-1]; 
            } else {
                // if today is a travel day,
                // three options
                int op1 = dp[i-1] + costs[0];
                int op2 = dp[max(i-7, 0)] + costs[1];
                int op3 = dp[max(i-30, 0)] + costs[2];
                dp[i] = min( {op1, op2, op3} );
            }
        }
        return dp[lastDay];
    }
};