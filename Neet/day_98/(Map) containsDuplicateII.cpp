class Solution 
{
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if (nums.empty()) return false;
        int n = nums.size();
        unordered_map<int, int> charToIdx;

        for (int i=0; i<n; i++) {
            if (charToIdx.count(nums[i]) && i-charToIdx[nums[i]] <= k) {
                return true;
            } else {
                charToIdx[nums[i]] = i;
            }
        }

        return false;
    }
};