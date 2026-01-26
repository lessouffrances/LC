class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            retrun a[0] < b[0];
        });

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for (int i=1; i<n; i++) {
            vector<int> currInterval = intervals[i];
            vector<int> prevInterval = mergedIntervals.back();

            if (currInterval[0] <= prevInterval[1]) {
                vector<int> merged(2, 0);
                merged[0] = min(currInterval[0], prevInterval[0]);
                merged[1] = max(currInterval[1], prevInterval[1]);
                mergedIntervals.pop_back();
                mergedIntervals.push_back(merged);
                continue;
            } 

            mergedIntervals.push_back(intervals[i]);
        }
        return mergedIntervals;

    }
};
