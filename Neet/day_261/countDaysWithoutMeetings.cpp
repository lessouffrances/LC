class Solution 
{
    public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        // since meetings may overlap
        // merge meetings first
        if (meetings.empty()) return 0;
        int n = meetings.size();

        sort(meetings.begin(), meetings.end());
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);

        for (int i=1; i<n; i++) {
            int currStart = meetings[i][0];
            int currEnd = meetings[i][1];
            int prevStart = merged.back()[0];
            int prevEnd = merged.back()[1];

            if (currStart <= prevEnd) {
                merged.pop_back();
                merged.push_back( { min(currStart, prevStart), max(currEnd, prevEnd) } );
            } else {
                merged.push_back( meetings[i] );
            }
        }

        int freeDays = 0;
        int prevEnd = 0;
        for (auto& interval : merged) {
            int start = interval[0];
            int end = interval[1];

            if (start > prevEnd+1) {
                // gap between (prevEnd+1) and (start-1) are freeDays
                freeDays += (start-1) - prevEnd; 
            }
            prevEnd = end;
        }
        freeDays += (days-prevEnd);
        return freeDays;
    }
};