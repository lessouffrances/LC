



// nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
// sorted_set = {1,5,9}

// Because we need three things simultaneously:
// Fast insertion and deletion — as the window slides, we add new elements and remove old ones → O(log k)
// Sorted order — to use lower_bound for range checking → if unsorted, you'd have to scan all k elements
// Duplicates — plain set would ignore duplicate values, but we need to keep them since they're at different indices

class Solution 
{
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        multiset<long> window;

        int n = nums.size();
        for (int i=0; i<n; i++) {
            auto iter = window.lower_bound((long)nums[i]-valueDiff);
            if (iter != window.end() && *iter <= nums[i] + valueDiff) return true;

            window.insert(nums[i]);

            // remove elements outside the window
            if (i >= indexDiff) {
                auto toRemove = window.find(nums[i - indexDiff]);
                window.erase(toRemove);
            }
        }
        return false;
    }
};