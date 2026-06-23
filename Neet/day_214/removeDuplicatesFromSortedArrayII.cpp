class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 1;
        int count = 1;
        for (int right=1; right<n; right++) {
            if (nums[right] == nums[right-1]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};