class Solution 
{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {{}};

        int n = intervals.size();
        // sort the intervals based on startTime
        // invariant: only when we sort the intervals based on StartTime
        //            the merge condition can apply: 
        //            currStart <= prevEnd

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back( intervals[0] );

        for (int i=1; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int prevEnd = merged.back()[1];

            // need to merge
            if (currStart <= prevEnd) {
                // the merged.back() need to be merged again
                vector<int> mergedOne = merged.back();
                merged.pop_back(); 
                mergedOne[1] = max(prevEnd, currEnd); 
                merged.push_back( mergedOne );
                continue;
            }
            // do not need to merge
            merged.push_back(intervals[i]);
        }
        return merged;
    }
};