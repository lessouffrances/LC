


// nums = [4,5,6,7,0,1,2], 
// target = 0

// Time: O(log N)
// Space: O(1)
class Solution 
{
    public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.empty()) return -1;

        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (target == nums[mid]) return mid;

            // left is sorted
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                // right is sorted
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};