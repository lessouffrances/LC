



class Solution 
{
    public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int rightBound = binarySearch(nums, target, true);
        if (rightBound == -1) return {-1, -1};
        int leftBound = binarySearch(nums, target, false);
        return {leftBound, rightBound};
    }

    private:
    // isFromLeft == true, search for right bound
    int binarySearch(vector<int>& nums, int target, bool isFromLeft)
    {
        int n = nums.size();
        int left = 0, right = n-1;

        int res = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                res = mid;
                if (isFromLeft) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }
};