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

            // if not at the start of a pair
            if (mid % 2 != 0) {
                mid -= 1;
            }

            // look to see if the pair is complete:
            // if complete: go to right
            if (mid+1 < n && nums[mid] == nums[mid+1]) {
                left = mid+2; // +2 because they are complete
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};