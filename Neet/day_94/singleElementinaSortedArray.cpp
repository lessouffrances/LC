class Solution 
{
    public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0, right = n-1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Ensure mid is at the start of a pair
            if (mid % 2 == 1) {
                mid--;
            }
            
            // Check if pair is complete
            if (nums[mid] == nums[mid + 1]) {
                // Pair is complete, single element is to the right
                left = mid + 2;
            } else {
                // Pair is broken, single element is to the left (or at mid)
                right = mid;
            }
        }
        
        return nums[left];

    }
};