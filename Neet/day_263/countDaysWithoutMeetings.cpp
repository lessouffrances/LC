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

        int freeDays = 0;
        // see if there are free days before the first meeting interval
        if (meetings[0][0] > 1) {
            freeDays += meetings[0][0] - 1;
        }

        for (int i=1; i<n; i++) {
            int currStart = meetings[i][0];
            int currEnd = meetings[i][1];
            int prevStart = merged.back()[0];
            int prevEnd = merged.back()[1];

            if (currStart-prevEnd-1 >= 1) {
                freeDays += currStart-prevEnd-1;
            }

            if (currStart <= prevEnd) {
                merged.pop_back();
                merged.push_back( { min(currStart, prevStart), max(currEnd, prevEnd) } );
            } else {
                merged.push_back( meetings[i] );
            }
        }

        if (days > merged.back()[1]) {
            freeDays += days-merged.back()[1];
        }
        return freeDays;
    }
};