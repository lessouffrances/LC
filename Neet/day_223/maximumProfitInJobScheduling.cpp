// greedy scheduling
// sort by endTime
// 
class Solution 
{
    public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        // step 1: bundle the startTime, endTime and profit
        int n = startTime.size();
        vector<vector<int>> intervals;
        for (int i=0; i<n; i++) {
            intervals.push_back( {startTime[i], endTime[i], profit[i]} );
        }

        // step 2: sort by endTime in non-descending order
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        // init the dp table
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        // dp[i] says, up until this i-th interval, what's the maximized value
        // populate the dp
        for (int i=1; i<=n; i++) {
            dp[i] = max(intervals[i-1][2] + dp[findPrevCompatibleIdx(i, intervals)], dp[i-1]);
        }
        return dp[n];
    }
    private:
    int findPrevCompatibleIdx(int idx, vector<vector<int>>& intervals)
    {
        auto iter = upper_bound(intervals.begin(), intervals.begin()+idx-1, 
        intervals[idx-1][0],
        [](int val, const auto& interval) {
            return val < interval[1];
        });
        return iter - intervals.begin();
    }
};