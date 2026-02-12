class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        // find the pivotIdx
        int pivotIdx = 0;
        bool found = false;
        for (int i=n-1; i>=0; i--) {
            if (i-1>=0 && nums[i-1] < nums[i]) {
                pivotIdx = i-1;
                found = true;
                break;
            }
        }
        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the swapIdx, which is the first one > pivotIdx
        // swap with pivotIdx
        int swapIdx = n-1;
        while (nums[swapIdx] <= nums[pivotIdx]) {
            swapIdx--;
        }
        swap(nums[swapIdx], nums[pivotIdx]);

        // reverse the portion after pivotIdx
        reverse(nums.begin()+pivotIdx+1, nums.end());
    }
};