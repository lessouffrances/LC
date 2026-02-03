





//  l   r
// [1,  0,  0,  3,  0,  12]



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
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};