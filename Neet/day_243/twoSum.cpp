class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        unordered_map<int, int> valToIdx;
        for (int i=0; i<n; i++) {
            int diff = target-nums[i];
            if (valToIdx.count(diff)) return {valToIdx[diff], i};
            valToIdx[nums[i]] = i;
        }
        return {-1, -1};
    }
};