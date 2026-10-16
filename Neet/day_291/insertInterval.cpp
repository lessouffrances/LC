class Solution 
{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if (intervals.empty()) return { newInterval };
        int n = intervals.size();
        
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            if (newStart > intervals[i][1]) {
                res.push_back(intervals[i]);
                continue;
            } else if (newEnd < intervals[i][0]) {
                res.push_back( {newStart, newEnd} );
                res.insert(res.end(), intervals.begin()+i, intervals.end());
                return res;
            } else {
                newStart = min(newStart, intervals[i][0]);
                newEnd = max(newEnd, intervals[i][1]);
                continue;
            }
        }
        res.push_back( {newStart, newEnd} );
        return res;
    }
};