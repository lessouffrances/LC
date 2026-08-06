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

        for (int i=1; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int prevEnd = mergedIntervals.back()[1];

            // if overlapped 
            if (currStart <= prevEnd) {
                int prevStart = mergedIntervals.back()[0];
                vector<int> mergedOne = { prevStart, max(currEnd, prevEnd) };
                mergedIntervals.pop_back();
                mergedIntervals.push_back(mergedOne);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }
        return mergedIntervals;
    }
};