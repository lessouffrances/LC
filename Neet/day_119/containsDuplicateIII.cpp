class Solution 
{
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        multiset<int> windowSet;
        int n = nums.size();

        for (int i=0; i<n; i++) {
            auto iter = windowSet.lower_bound(nums[i]-valueDiff);
            if (iter != windowSet.end() && *iter <= nums[i]+valueDiff) {
                return true;
            }

            windowSet.insert(nums[i]);

            // shrink window
            if (i >= indexDiff) {
                auto toRemove = windowSet.find(nums[i-indexDiff]);
                windowSet.erase(toRemove);
            }
        }
        return false;
    }
};