class Solution 
{
    public:
    long long minOperations(vector<int>& nums) 
    {
        long long res = 0;
        for (int i=0; i+1<nums.size(); i++) {
            res += max(0, nums[i]-nums[i+1]);
        }
        return res;
    }
};