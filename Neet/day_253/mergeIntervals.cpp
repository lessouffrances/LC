class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i=1; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int prevStart = merged.back()[0];
            int prevEnd = merged.back()[1];

            // detect overlap
            if (currStart <= prevEnd) {
                merged.pop_back();
                vector<int> mergedOne = {min(currStart, prevStart), max(currEnd, prevEnd)};
                merged.push_back(mergedOne);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};