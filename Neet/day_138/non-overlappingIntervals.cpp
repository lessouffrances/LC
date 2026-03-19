

// Time: O(N logN)
// Space: O(1)
class Solution 
{
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        int n = intervals.size();

        // sort based on endTime
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int count = 0;
        int prevEndTime = intervals[0][1];
        for (int i=1; i<n; i++) {
            int currStartTime = intervals[i][0];
            int currEndTime = intervals[i][1];

            if (currStartTime < prevEndTime) {
                count++;
            } else {
                prevEndTime = currEndTime;
            }
        }
        return count;
    }
};