



class Solution 
{
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        multiset<long> windowSet;
        int n = nums.size();

        for (int i=0; i<n; i++) {
            // use multiset op: lower_bound to check:
            // where is the first element in the window that 
            // could possibly >= nums[i]-valueDiff ?"
            auto iter = windowSet.lower_bound( (long) nums[i]-valueDiff );
            if (iter != windowSet.end() && *iter <= nums[i] + valueDiff) {
                return true;
            }
            windowSet.insert(nums[i]);

            // remove the nums outside the index range
            if (i >= indexDiff) {
                auto toRemove = windowSet.find(nums[i-indexDiff]);
                windowSet.erase(toRemove);
            }
        }
        return false;
    }
};