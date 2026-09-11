class Solution 
{
    public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if (points.empty()) return 0;
        int n = points.size();

        // sort by start time
        sort(points.begin(), points.end());
        vector<vector<int>> merged;
        merged.push_back(points[0]);

        for (int i=1; i<n; i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];
            int prevStart = merged.back()[0];
            int prevEnd = merged.back()[1];

            if (currStart <= prevEnd) {
                merged.pop_back();
                merged.push_back( { max(currStart, prevStart), min(currEnd, prevEnd) } );
            } else {
                merged.push_back(points[i]);
            }
        }
        return merged.size();
    }
};