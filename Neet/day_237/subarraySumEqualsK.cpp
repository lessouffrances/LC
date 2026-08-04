class Solution 
{
    public:
    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        // we need to return the headcount 
        // of subarrays that summed up to k
        unordered_map<int, int> prefixSumCounter;
        prefixSumCounter[0] = 1;

        int count = 0;
        int currSum = 0;
        for (int& num : nums) {
            currSum += num;
            int diff = currSum-k;
            count += prefixSumCounter[diff];
            prefixSumCounter[currSum]++;
        }
        return count;
    }
};