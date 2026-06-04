class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i=1; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int prevStart = merged.back()[0];
            int prevEnd = merged.back()[1];

            if (currStart <= prevEnd) {
                merged.pop_back();
                vector<int> mergedOne = { prevStart, max(prevEnd, currEnd) };
                merged.push_back(mergedOne);
                continue;
            }
            merged.push_back(intervals[i]);
        }

        return merged;
    }
};