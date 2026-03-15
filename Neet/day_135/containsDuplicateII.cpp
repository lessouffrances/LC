class Solution 
{
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        int left = 0;
        unordered_set<int> window;
        for (int right=0; right<n; right++) {
            if (window.count(nums[right])) return true;
            window.insert(nums[right]);
            if (right-left+1 > k) {
                window.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};