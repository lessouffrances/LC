







class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};
        int n = intervals.size();

        // sort by startTime
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        merged.push_back( intervals[0] );

        for (int i=1; i<intervals.size(); i++) {
            int currStartTime = intervals[i][0];
            int currEndTime = intervals[i][1];
            int prevStartTime = merged.back()[0];
            int prevEndTime = merged.back()[1];

            if (currStartTime <= prevEndTime) {
                vector<int> mergedInterval = { prevStartTime, max(currEndTime, prevEndTime) };
                merged.pop_back();
                merged.push_back(mergedInterval);
                continue;
            }

            merged.push_back(intervals[i]);
        }

        return merged;
    }
};