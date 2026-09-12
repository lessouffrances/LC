class Solution
{
    public:
    bool hasIntervalConflict(vector<int>& candidate, vector<vector<int>>& intervals)
    {
        if (intervals.empty()) return false;
        
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int candidateStart = candidate[0];
        int candidateEnd = candidate[1];

        // find the first interval whose start >= candidateStart
        int idx = n;
        for (int i=0; i<n; i++) {
            if (intervals[i][0] >= candidateStart) {
                idx = i;
                break;
            }
        }
        // int idx = lower_bound(intervals.begin(), intervals.end(),
        //                        vector<int>{candidateStart, INT_MIN})-intervals.begin();

        if (idx < intervals.size()) {
            int currStart = intervals[idx][0];
            int currEnd = intervals[idx][1];
            if (candidateStart < currEnd && currStart < candidateEnd) return true;
        }
        if (idx > 0) {
            int currStart = intervals[idx-1][0];
            int currEnd = intervals[idx-1][1];
            if (candidateStart < currEnd && currStart < candidateEnd) return true;
        }
        return false;
    }
};