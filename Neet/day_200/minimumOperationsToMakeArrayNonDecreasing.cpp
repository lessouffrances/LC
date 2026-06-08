class Solution 
{
    public:
    long long minOperations(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        long long res = 0;
        for (int i=0; i<n-1; i++) {
            // add the drop gap
            res += max(0, nums[i]-nums[i+1]);
        }
        return res;
    }
};
    