class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};
        int n = intervals.size();

        // sort by startTime
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i=1; i<n; i++) {
            vector<int>& last = merged.back();
            if (intervals[i][0] <= last[1]) {
                last[1] = max(intervals[i][1], last[1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};