class Solution 
{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if (intervals.empty()) return { newInterval };
        int n = intervals.size();

        vector<vector<int>> mergedIntervals;

        for (int i=0; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int newIntervalStart = newInterval[0];
            int newIntervalEnd = newInterval[1];

            if (newIntervalStart > currEnd) {
                mergedIntervals.push_back(intervals[i]);
                continue;
            } else if (newIntervalEnd < currStart) {
                mergedIntervals.push_back(newInterval);
                mergedIntervals.insert(mergedIntervals.end(), intervals.begin()+i, intervals.end());
                return mergedIntervals;
            } else {
                // need merge
                vector<int> mergedOne = { min(newIntervalStart, currStart), max(newIntervalEnd, currEnd) };
                newInterval = mergedOne;
                continue;
            }
        }
        mergedIntervals.push_back(newInterval);
        return mergedIntervals;
    }
};