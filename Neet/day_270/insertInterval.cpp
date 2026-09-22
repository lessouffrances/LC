class Solution 
{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n = intervals.size();
        vector<vector<int>> mergedIntervals;

        for (int i=0; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int newIntervalStart = newInterval[0];
            int newIntervalEnd = newInterval[1];

            if (newIntervalEnd < currStart) {
                mergedIntervals.push_back(newInterval);
                mergedIntervals.insert(mergedIntervals.end(), intervals.begin()+i, intervals.end());
                return mergedIntervals;
            } else if (newIntervalStart > currEnd) {
                mergedIntervals.push_back(intervals[i]);
                continue;
            } else {
                // overlap
                vector<int> mergedOne = { min(currStart, newIntervalStart), max(currEnd, newIntervalEnd) };
                newInterval = mergedOne;
                continue;
            }
        }
        mergedIntervals.push_back(newInterval);
        return mergedIntervals;
    }
};