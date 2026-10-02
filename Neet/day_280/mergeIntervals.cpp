class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for (int i=1; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int prevStart = mergedIntervals.back()[0];
            int prevEnd = mergedIntervals.back()[1];

            if (currStart <= prevEnd) {
                mergedIntervals.pop_back();
                vector<int> mergedOne = { min(currStart, prevStart), max(currEnd, prevEnd) };
                mergedIntervals.push_back(mergedOne);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }
        return mergedIntervals;
    }
};