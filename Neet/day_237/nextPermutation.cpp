// 1 4 5 8 7
class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        int pivotIdx = -1;
        // the pivotIdx is the one that drops for the first time
        // when counting from the rbegin
        bool found = false;
        for (int i=n-1; i>0; i--) {
            if (nums[i-1] < nums[i]) {
                pivotIdx = i-1;
                found = true;
                break;
            }
        }

        // if there's no such drop from the end,
        // the next permutation is simply the reversion
        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int swapIdx = n-1;
        while (nums[swapIdx] <= nums[pivotIdx]) {
            swapIdx--;
        }
        swap(nums[swapIdx], nums[pivotIdx]);
        reverse(nums.begin()+pivotIdx+1, nums.end());
        return;
    }
};