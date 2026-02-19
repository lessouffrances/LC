class Solution 
{
    public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if (points.empty()) return 0;
        int n = points.size();

        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        // once find overlap, take the common portion of 2 intervals 
        vector<vector<int>> merged;
        merged.push_back(points[0]);

        for (int i=1; i<n; i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];
            int prevStart = merged.back()[0];
            int prevEnd = merged.back()[1];

            if (currStart <= prevEnd) {
                vector<int> mergedOne = {max(prevStart, currStart), min(prevEnd, currEnd)};
                merged.pop_back();
                merged.push_back(mergedOne);
                continue;
            }
            merged.push_back(points[i]);
        }
        return merged.size();
    }
};