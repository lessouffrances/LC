class Solution 
{
    public:
    int removeElement(vector<int>& nums, int val) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int left = 0;
        for (int right=0; right<n; right++) {
            if (nums[right] == val) continue;
            nums[left] = nums[right];
            left++;
        }
        return left;
    }
};