class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};
        int n = intervals.size();
        // sorted by the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        // overlap condition: 
        // currStart <= prevEnd
        for (int i=1; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int prevStart = res.back()[0];
            int prevEnd = res.back()[1];

            if (currStart <= prevEnd) {
                res.pop_back();
                res.push_back( { min(currStart, prevStart), max(currEnd, prevEnd) } );
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};