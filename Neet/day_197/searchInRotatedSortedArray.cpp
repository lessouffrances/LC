// nums = [4,5,6,7,0,1,2], target = 0
class Solution 
{
    public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.empty()) return -1;

        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] >= nums[left]) {
                // left half is sorted
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                // right half is sorted
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