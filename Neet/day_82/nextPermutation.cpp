class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        bool found = false;
        int n = nums.size();

        // from the end to begin, expect it to increase, if it stops increasing, pivot idx
        int pivot;
        for (int i=n-1; i>=1; i--) {
            if (nums[i-1] < nums[i]) {
                pivot = i-1;
                found = true;
                break;
            }
        }

        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // go from the right, find the very first idx that's greater than the nums[pivot]
        int swap = n-1;
        while (nums[swap] <= nums[pivot]) {
            swap--;
        }

        int temp = nums[pivot];
        nums[pivot] = nums[swap];
        nums[swap] = temp;

        reverse(nums.begin()+pivot+1, nums.end());        
    }
};