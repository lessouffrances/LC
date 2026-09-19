class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        int pivotIdx = -1;
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

        int swapIdx = n-1;
        while (nums[swapIdx] <= nums[pivotIdx]) {
            swapIdx--;
        }

        swap(nums[pivotIdx], nums[swapIdx]);
        reverse(nums.begin()+pivotIdx+1, nums.end());
        return;
    }
};