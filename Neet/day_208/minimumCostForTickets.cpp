// Recurrence analysis:
// subproblem: up until i-th day, how much is the optimal cost?
// the dp ranges from day 1 to the last day of the given days

// for any day in the dp
// if the day is NOT a travel day, dp[i] = dp[i-1]
// if the day is a travel day
// choose the optimal val among these three options:
// dp[i] = max(dp[i-1], 0)+cost[0];
// dp[i] = max(dp[i-7], 0)+cost[1];
// dp[i] = max(dp[i-30], 0)+cost[2];

class Solution 
{
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        if (days.empty()) return 0;
        int lastDay = *max_element(days.begin(), days.end());
        unordered_set<int> travelDays(days.begin(), days.end());

        vector<int> dp(lastDay+1, 0); 
        // up to i-th day, what is the minimum cost to cover all travel days

        for (int day=1; day<=lastDay; day++) {
            if (!travelDays.count(day)) {
                dp[day] = dp[day-1]; // do not incur addtional cost
            } else {
                int oneDay = dp[day-1]+costs[0];
                int sevenDay = dp[max(day-7, 0)]+costs[1];
                int thirtyDay = dp[max(day-30, 0)]+costs[2];

                dp[day] = min( {oneDay, sevenDay, thirtyDay} );
            }
        }
        return dp[lastDay];
    }
};