




// nums = [1, 3, 12, 3, 12]
//               l,     r 


class Solution 
{
    public:
    void moveZeroes(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        int left = 0;
        for (int right=0; right<n; right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }
        while (left < n) {
            nums[left] = 0;
            left++;
        }
        return;
    }
};