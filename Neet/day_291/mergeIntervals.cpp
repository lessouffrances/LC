class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        // int prevStart = intervals[0][0];
        // int prevEnd = intervals[0][1];

        for (int i=1; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int prevStart = res.back()[0];
            int prevEnd = res.back()[1];

            // check if overlap
            if (currStart <= prevEnd) {
                res.pop_back();
                vector<int> mergedOne = { min(prevStart, currStart), max(prevEnd, currEnd) };
                res.push_back(mergedOne);
            } else {
                res.push_back(intervals[i]);
            }
        }    
        return res;    
    }
};