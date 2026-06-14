
// 1 4 5 8 7
class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;

        int n = nums.size();
        int pivotIdx = -1;
        bool found = false;
        for (int i=n-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                pivotIdx = i;
                found = true;
                break;
            }
        }
        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // the swapIdx: from the right, the first idx > pivot idx
        int swapIdx = n-1;
        while (nums[swapIdx] <= nums[pivotIdx]) {
            swapIdx--;
        }

        swap(nums[swapIdx], nums[pivotIdx]);
        reverse(nums.begin()+pivotIdx+1, nums.end());
    }
};