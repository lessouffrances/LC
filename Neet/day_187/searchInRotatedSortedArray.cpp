class Solution 
{
    public:
    // nums = [4,5,6,7,8,0,1,2], target = 0
    int search(vector<int>& nums, int target) 
    {
        if (nums.empty()) return -1;
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {
                // left half is all sorted
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                // right half is all sorted
                if (target >= nums[mid] && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};