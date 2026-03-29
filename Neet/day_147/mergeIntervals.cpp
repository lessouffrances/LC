

// Time: O(N logN)
// Space: O(N)
class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};
        int n = intervals.size();

        // sort based on startTime in asc 
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i=1; i<n; i++) {
            int currStartTime = intervals[i][0];
            int currEndTime = intervals[i][1];
            int prevEndTime = merged.back()[1];

            if (currStartTime <= prevEndTime) {
                vector<int> detached = merged.back();
                merged.pop_back();
                vector<int> attached = {detached[0], max(currEndTime, prevEndTime)};
                merged.push_back(attached);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};