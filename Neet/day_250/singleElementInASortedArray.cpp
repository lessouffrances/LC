class Solution 
{
    public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2;

            // see if the mid is the start of a pair
            if (mid % 2 != 0) {
                mid -= 1;
            }

            if (mid+1 < n && nums[mid] == nums[mid+1]) {
                left = mid+2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};