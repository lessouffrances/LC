class Solution 
{
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int numOfNonOverlapping = 1;
        vector<int> prevInterval = intervals[0];

        for (int i=0; i<n; i++) {
            vector<int> currInterval = intervals[i];
            if (currInterval[0] >= prevInterval[1]) {
                numOfNonOverlapping++;
                prevInterval = currInterval;
            }
        }
        return n - numOfNonOverlapping;
    }
};
    