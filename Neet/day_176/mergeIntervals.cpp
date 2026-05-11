

class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        int prevEndTime = intervals[0][1];
        int prevStartTime = intervals[0][0];

        for (int i=1; i<n; i++) {
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];
            prevEndTime = mergedIntervals.back()[1];
            prevStartTime = mergedIntervals.back()[0];

            // check for overlap
            if (startTime <= prevEndTime) {
                mergedIntervals.pop_back();
                vector<int> merged = { min(startTime, prevStartTime), max(endTime, prevEndTime) };
                mergedIntervals.push_back(merged);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }
        return mergedIntervals;
    }
};