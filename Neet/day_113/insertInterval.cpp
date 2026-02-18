class Solution 
{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if (intervals.empty()) return { newInterval };
        int n = intervals.size();
        vector<vector<int>> merged;
        for (int i=0; i<intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) {
                // newInterval before this interval
                merged.push_back(newInterval);
                // insert and return
                merged.insert(merged.end(), intervals.begin()+i, intervals.end());
                return merged;
            } else if (newInterval[0] > intervals[i][1]) {
                // after
                merged.push_back(intervals[i]);
            } else {
                // overlap: merged this interval with the newInterval and substitute
                vector<int> mergedOne = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
                newInterval = mergedOne; // sub
            }
        }
        merged.push_back(newInterval);
        return merged;
    }
};