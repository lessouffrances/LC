class Solution 
{
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        int left = 0;
        unordered_set<int> seen;
        for (int right=0; right<n; right++) {
            if (right - left > k) {
                seen.erase(nums[left]);
                left++;
            }

            if (seen.count(nums[right])) return true;
            seen.insert(nums[right]);
        }
        
        return false;
    }
};