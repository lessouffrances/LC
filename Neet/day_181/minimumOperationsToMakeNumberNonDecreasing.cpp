class Solution 
{
    public:
    long long minOperations(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        long long res = 0;
        for (int i=n-2; i>=0; i--) {
            // detect a drop
            if (nums[i] > nums[i+1]) {
                res += (nums[i]-nums[i+1]); 
            }
        }
        return res;
    }
};