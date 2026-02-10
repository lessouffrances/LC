class Solution 
{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if (intervals.empty()) return { newInterval };

        int n = intervals.size();
        vector<vector<int>> merged;
        for (int i=0; i<n; i++) {
            if (newInterval[1] < intervals[i][0]) {
                // appear before current interval
                merged.push_back(newInterval);
                merged.insert(merged.end(), intervals.begin()+i, intervals.end());
                return merged;
            } else if (newInterval[0] > intervals[i][1]) {
                // appear after current interval
                merged.push_back(intervals[i]);
            } else {
                newInterval = { min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1]) }; 
            }
        }

        merged.push_back(newInterval);
        return merged;
    }
};