

// 1 4 5 8 7
class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        // find the pivot idx, from right to left
        // the first one that is < 
        int pivotIdx;
        bool found = false;
        for (int i=n-1; i>=1; i--) {
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

        // find the first one that is > pivotIdx
        // from right to left
        // swap with the pivotIdx
        int swapIdx;
        for (int i=n-1; i>=0; i--) {
            if (nums[i] > nums[pivotIdx]) {
                swap(nums[i], nums[pivotIdx]);
                break;
            }
        }

        // reverse the portion after pivotIdx
        reverse(nums.begin()+pivotIdx+1, nums.end());
        return;
    }
};