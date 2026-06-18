class Solution 
{
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        unordered_set<int>travelDays(days.begin(), days.end());
        int lastDay = *max_element(days.begin(), days.end());

        vector<int>dp(lastDay+1, INT_MAX);
        dp[0] = 0;

        for (int day=1; day<=lastDay; day++) {
            if (!travelDays.count(day)) {
                dp[day] = dp[day-1];
            } else {
                int oneDayPass = dp[day-1]+costs[0];
                int sevenDayPass = dp[max(day-7, 0)]+costs[1];
                int thirtyDayPass = dp[max(day-30, 0)]+costs[2];

                dp[day] = min( {oneDayPass, sevenDayPass, thirtyDayPass} );
            }
        }
        return dp[lastDay];
    }
};