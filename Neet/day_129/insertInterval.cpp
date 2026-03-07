class Solution 
{
    public:
    // Invariant: sort the intervals based on startTime such that we can apply merge condition
    // merge condition: 
    // when currStart < or <=  prevEnd, => merge
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if (intervals.empty()) return { newInterval };
        int n = intervals.size();

        vector<vector<int>> merged;

        // starts with 0
        for (int i=0; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            int newIntervalStart = newInterval[0];
            int newIntervalEnd = newInterval[1];

            if (newIntervalStart > currEnd) {
                // if the newInterval comes after the currInterval End 
                merged.push_back(intervals[i]);
                continue;

            } else if (newIntervalEnd < currStart) {
                // if the newInterval comes before the currInterval Start
                merged.push_back(newInterval);
                // insert the rest of the intervals into merged
                merged.insert(merged.end(), intervals.begin()+i, intervals.end());
                return merged;

            } else {
                // if overlap
                // substitute and let the flow go
                vector<int> mergedOne = { min(currStart, newIntervalStart), max(currEnd, newIntervalEnd) };
                newInterval = mergedOne;
                continue;
            }
        }

        merged.push_back(newInterval);
        return merged;
    }
};