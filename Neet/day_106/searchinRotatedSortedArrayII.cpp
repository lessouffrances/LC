







class Solution 
{
    public:
    bool search(vector<int>& nums, int target) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        int left = 0, right = n-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) return true;
            if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
                left++;
                right--;
                continue;
            } 

            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return false;
    }
};