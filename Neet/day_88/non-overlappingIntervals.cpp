// intervals = [[1,2],[2,3],[1,3],[3,4]]

class Solution 
{
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        int n = intervals.size();

        // sort the intevals by endTime
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int count = 1;
        vector<int> preInterval = intervals[0];
        for (int i=1; i<n; i++) {
            if (intervals[i][0] >= preInterval[1]) {
                preInterval = intervals[i];
                count++;
            }
        }
        return n-count;
    }
};