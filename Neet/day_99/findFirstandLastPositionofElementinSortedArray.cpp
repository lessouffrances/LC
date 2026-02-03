class Solution 
{
    public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {-1, -1};
        return { binarySearchFindBound(target, nums, true), binarySearchFindBound(target, nums, false) };
    }
    private:
    int binarySearchFindBound(int target, vector<int>& nums, bool goLeft)
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0, right = n-1;

        int bound = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid;

                // even if found, still cannot stop
                if (goLeft) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }

            if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return bound;
    }
};