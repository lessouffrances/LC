

//         0,1,2,3,4,5,6
// nums = [4,5,6,7,0,1,2], target = 0
class Solution 
{
    public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int left = 0, right = n-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            if (target == nums[mid]) return mid;

            // figure out which half is sorted
            if (nums[mid] >= nums[left]) {
                // left half is sorted
                // then check if the target is in the range
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid-1;
                } else {
                    // target >= nums[mid] && target < nums[left]
                    left = mid+1;
                }
            } else {
                // right half is sorted
                // then check if the target is in the range
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