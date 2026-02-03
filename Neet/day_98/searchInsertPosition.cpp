class Solution 
{
    public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int left = 0, right = n-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } 

            if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};