class Solution 
{
    public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {-1, -1};
        return { findBound(nums, target, true), findBound(nums, target, false) };
    }
    private:
    int findBound(vector<int>& nums, int target, bool goLeft)
    {
        int left = 0, right = nums.size()-1;
        int bound = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                bound = mid;

                if (goLeft) {
                    right = mid - 1; // search left half 
                } else {
                    left = mid + 1; // search right half
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return bound;
    }
};