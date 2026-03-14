



// 1 4 5 8 7
class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;

        // find the pivotIdx:
        // go from the right, the first one thats' < than the i+1
        int n = nums.size();
        int pivotIdx = -1;
        for (int i=n-1; i>=1; i--) {
            if (nums[i-1] < nums[i]) {
                pivotIdx = i-1;
                break;
            }
        }

        // if no pivotIdx 
        if (pivotIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the swapIdx
        // go from the right, the first one that's greater than the pivotIdx num
        int swapIdx = n-1;
        while (nums[swapIdx] <= nums[pivotIdx]) {
            swapIdx--;
        }

        // swap
        swap(nums[swapIdx], nums[pivotIdx]);
        // reverse the part after the pivotIdx
        reverse(nums.begin()+pivotIdx+1, nums.end());
        return;
    }
};