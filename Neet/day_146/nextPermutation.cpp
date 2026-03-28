


// Time: O(N)
// Space: O(1)
// 1 4 5 8 7
class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        // find the pivot index
        int pivotIdx = -1;
        bool found = false;
        for (int i=n-1; i>0; i--) {
            if (nums[i-1] < nums[i]) {
                pivotIdx = i-1;
                found = true;
                break;
            }
        }

        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        } 

        // find the swapIdx
        // go from the right, the first idx that is <= the pivotIdx
        int swapIdx = n-1;
        while (nums[swapIdx] <= nums[pivotIdx]) {
            swapIdx--;
        }

        swap(nums[swapIdx], nums[pivotIdx]);
        // reverse the part after pivotIdx
        reverse(nums.begin()+pivotIdx+1, nums.end());
        return;
    }
};