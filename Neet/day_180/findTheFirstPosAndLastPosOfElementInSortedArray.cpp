class Solution 
{
    public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.empty()) {
            return {-1, -1};
        }

        int firstPos = searchRangeHelper(nums, target, true);
        if (firstPos == -1) return {-1, -1};
        int secondPos = searchRangeHelper(nums, target, false);
        return {firstPos, secondPos};
    }
    private:
    // returns the index 
    int searchRangeHelper(vector<int>& nums, int target, bool isFromLeft)
    {
        if (nums.empty()) return -1;

        int left = 0, right = nums.size()-1;
        int bound = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                bound = mid;
                // not done yet, keep searching
                // keep searching
                if (isFromLeft) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return bound;
    }
};
