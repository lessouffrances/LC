class Solution 
{
    public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = profit.size();
        vector<vector<int>> intervals;
        for (int i=0; i<n; i++) {
            intervals.push_back( {  startTime[i], endTime[i], profit[i] } );
        }

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        }); 

        vector<int> sortedProfit;
        for (auto& interval : intervals) {
            sortedProfit.push_back(interval[2]);
        }

        vector<int> dp(n+1, 0);
        auto findPrevCompatible = [&](int idx) {
            int left = 0, right = idx-2;
            while (left <= right) {
                int mid = left + (right-left)/2;
                if (intervals[mid][1] <= intervals[idx-1][0]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            return left;
        };

        for (int i=1; i<dp.size(); i++) {
            dp[i] = max(dp[i-1], sortedProfit[i-1]+dp[findPrevCompatible(i)]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};