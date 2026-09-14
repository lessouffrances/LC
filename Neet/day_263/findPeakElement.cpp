class Solution 
{
    public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.empty()) return -1;

        int n = nums.size();
        int left = 0, right = n-1;
        // what is the homo-feature for the left half?
        // the next one is strictly greater than this one
        while (left < right) {
            int mid = left + (right-left)/2;

            if (mid+1 < n && nums[mid]<nums[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};