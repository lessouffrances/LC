class Solution 
{
    public:
    vector<int> runningSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int> res(n, 0);
        int currSum = 0;
        for (int i=0; i<n; i++) {
            currSum += nums[i];
            res[i] = currSum;
        }
        return res;
    }
};