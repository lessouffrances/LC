







class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;

        // find the pivot number
        int n = nums.size();
        int pivotIdx = 0;
        bool found = false;
        for (int i=n-1; i>=0; i--) {
            if (i-1 >= 0 && nums[i-1] < nums[i]) {
                pivotIdx = i-1;
                found = true;
                break;
            }
        }
        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // go from the right and find the first idx thats greater than pivot
        int swapIdx = n-1;
        while (nums[swapIdx] <= nums[pivotIdx]) {
            swapIdx--;
        }

        // swap that number with the pivotIdx
        swap(nums[swapIdx], nums[pivotIdx]);

        // reverse the portion after the pivotIdx
        reverse(nums.begin()+pivotIdx+1, nums.end());
    }
};