


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
            // newInterval is not a constant
            int newIntervalStart = newInterval[0];
            int newIntervalEnd = newInterval[1];

            if (currEnd < newIntervalStart) {
                // need to push curr
                mergedIntervals.push_back(intervals[i]);
                continue;
            } else if (newIntervalEnd < currStart) {
                // need to push the newInterval first
                // insert all the remaining intervals and return
                mergedIntervals.push_back(newInterval);
                mergedIntervals.insert(mergedIntervals.end(), intervals.begin()+i, intervals.end());
                return mergedIntervals;
            } else {
                // overlap
                vector<int> mergedOne = { min(currStart, newIntervalStart), max(currEnd, newIntervalEnd) };
                newInterval = mergedOne;
                continue;
            }
        }
        return mergedIntervals;
    }
};