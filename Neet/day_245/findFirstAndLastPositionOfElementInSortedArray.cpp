// nums = [5,7,7,8,8,10]
class Solution 
{
    public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {-1, -1};
        int leftBound = binarySearchWithDir(nums, target, false);
        if (leftBound == -1) return {-1, -1};
        int rightBound = binarySearchWithDir(nums, target, true);
        return { leftBound, rightBound };
    }

    private:
    // "isFromLeft == true" => right bound
    int binarySearchWithDir(vector<int>& nums, int target, int isFromLeft)
    {
        if (nums.empty()) return -1;
        int n = nums.size();

        int left = 0, right = n-1;
        int bound = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                bound = mid;
                if (isFromLeft) {
                    left = mid+1;
                } else {
                    right = mid-1;
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