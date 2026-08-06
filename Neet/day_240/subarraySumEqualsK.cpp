class Solution 
{
    public:
    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        int currSum = 0;
        int count = 0;
        for (int i=0; i<n; i++) {
            currSum += nums[i];
            int diff = currSum-k;
            count += prefixSum[diff];
            prefixSum[currSum]++;
        }
        return count;
    }
};