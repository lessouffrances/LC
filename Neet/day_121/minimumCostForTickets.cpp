class Solution 
{
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        // recurrence analysis
        // subproblem: up until i-th day, how much is the optimal cost?
        // the dp ranges from day 1 to the last day in days

        if (costs.empty() || days.empty()) return 0;
        int lastDay = *max_element(days.begin(), days.end());
        unordered_set<int> travelDays(days.begin(), days.end());

        vector<int>dp(lastDay+1, 0);
        for (int day=1; day<=lastDay; day++) 
        {
            if (!travelDays.count(day)) {
                dp[day] = dp[day-1];
            } else {
                int oneDay = dp[ max(0, day-1) ] + costs[0];
                int sevenDay = dp[ max(0, day-7) ] + costs[1];
                int thirtyDay = dp[ max(0, day-30) ] + costs[2];

                dp[day] = min( {oneDay, sevenDay, thirtyDay} );
            }
        }
        return dp[lastDay];
    }
};