class Solution 
{
    public:
    int singleNumber(vector<int>& nums) 
    {
        if (nums.empty()) return -1;
        int n = nums.size();

        int currNum = nums[0];
        for (int i=1; i<n; i++) {
            currNum ^= nums[i];
        }
        return currNum;
    }
};