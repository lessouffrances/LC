

//         i
// nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3

class Solution 
{
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        int n = nums.size();

        for (int right=0; right<n; right++) {

            for (int i=max(0, right-indexDiff); i<=min(right+indexDiff, n-1); i++) {
                if (i == right) continue;
                // check if there are valid numbers within:
                // [nums[right]-valueDiff, nums[right]+valueDiff]
                if (nums[i] >= nums[right]-valueDiff && nums[i] <= nums[right]+valueDiff) {
                    return true;
                }
            }
        }
        return false;
    }
};