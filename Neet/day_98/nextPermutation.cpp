class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();
        bool found = false;

        int pivot;
        for (int i=n-1; i>=1; i--) {
            if (nums[i-1] <= nums[i]) {
                pivot = i-1;
                found = true;
                break;
            }
        }
        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // go from the right
        // find the first idx that's greater than the pivot num
        int swap = n-1;
        while (nums[swap] <= nums[pivot]) {
            swap--;
        }

        int temp = nums[swap];
        nums[swap] = nums[pivot];
        nums[pivot] = temp;

        // reverse the portion after pivot
        reverse(nums.begin()+pivot+1, nums.end());
    }
};