class Solution 
{
    public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left) / 2;

            // ensure mid is at the start of a pair
            if (mid % 2 == 1) {
                mid = mid-1;
            }
            // if the pair is complete, go to the right
            if (nums[mid] == nums[mid+1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};