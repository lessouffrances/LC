class Solution 
{
    public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.empty()) return { -1, -1 };
        return { binarySearchFindBound(target, nums, true),  
            binarySearchFindBound(target, nums, false) };
    }
    private:
    // if goLeft, the search will continue to the left
    int binarySearchFindBound(int target, vector<int>& nums, bool isGoLeft)
    {
        int n = nums.size();
        int left = 0, right = n-1;
        
        int bound = -1;
        while (left <= right) {
            int mid = left + (right-left) / 2;

            if (nums[mid] == target) {
                bound = mid;
                // not done yet
                if (isGoLeft) {
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