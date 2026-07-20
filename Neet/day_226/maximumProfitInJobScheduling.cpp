class Solution 
{
    public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        // greedily sort the intervals by endTime
        int n = profit.size();
        // bundle
        vector<vector<int>> intervals;
        for (int i=0; i<n; i++) {
            intervals.push_back( {startTime[i], endTime[i], profit[i]} );
        }
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        // subproblem:
        // dp[i] says, up until this i-th interval, what's the maximized profit?
        vector<int> dp(n+1, 0);
        // base case
        // dp[0] = 0; 
        for (int i=1; i<n+1; i++) {
            // take i-th profit
            int take = dp[findPrevCompatible(i, intervals)] + intervals[i-1][2];
            // skip i-th profit
            int skip = dp[i-1];
            // max
            dp[i] = max(take, skip);
        }
        return dp[n];
    }

    private:
    int findPrevCompatible(int idx,  vector<vector<int>>& intervals)
    {
        idx--;
        int left = 0, right = idx-1;

        int res = -1;
        while (left<=right) {
            int mid = left + (right-left)/2;
            if (intervals[mid][1] <= intervals[idx][0]) {
                res = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res+1;
    }
};