class Solution 
{
    public:
        void nextPermutation(vector<int>& nums) 
        {
            // find the pivot point
            bool found = false;
            int n = nums.size();
            int pivot;
            for (int i=n-1; i>=1; i--) {
                if (nums[i-1]<nums[i]) {
                    pivot = i-1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                return reverse(nums.begin(), nums.end());
            }

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