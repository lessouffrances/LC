class Solution 
{
    public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        merged,push_back(nums[0]);
        for (int i=1; i<n; i++) {
            int currStart = nums[i][0];
            int currEnd = nums[i][1];
            int prevStart = merged.back()[0];
            int prevEnd = merged.back()[1];

            if (currStart <= prevEnd) {
                merged.pop_back();
                vector<int> mergedOne = {min(prevStart, currStart), max(prevEnd, currEnd)};
                merged.push_back(mergedOne);
                continue;
            }
            merged.push_back(nums[i]);
        }

        int res = 0;
        for (auto& covered : merged) {
            int start = covered[0];
            int end = covered[1];

            res += (end - start + 1);
        }
        return res;
    }
};