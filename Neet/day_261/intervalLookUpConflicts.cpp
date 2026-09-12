class Solution
{
    public:
    bool hasIntervalConflict(vector<int>& candidate, vector<vector<int>>& intervals)
    {
        if (intervals.empty()) return false;

        int candStart = candidate[0];
        int candEnd = candidate[1];  // exclusive

        for (auto& interval : intervals) {
            int currStart = interval[0];
            int currEnd = interval[1];  // exclusive

            // two half-open intervals [a, b) and [c, d) overlap
            // iff a < d AND c < b
            if (candStart < currEnd && currStart < candEnd) {
                return true;
            }
        }
        return false;
    }
};