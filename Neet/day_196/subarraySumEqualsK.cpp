class Solution 
{
    public:
    //  diff                k            currSum
    // prefixSum[0...i] + subarraySum = prefixSum[0...j]
    // nums = [1,2,3], k = 3
    // prefixSum = {{0,1}, {1,1}, {3,1}, {6,1}}
    // currSum = 1, diff = 1-3 = -2
    // currSum = 3, diff = 0, count = 1
    // currSum = 6, diff = 6-3 = 3 count = 2
    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        int count = 0;
        unordered_map<int, int> prefixSumToCount; 
        prefixSumToCount[0] = 1;
        int currSum = 0;
        for (int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            int diff = currSum - k;
            if (prefixSumToCount.count(diff)) {
                count += prefixSumToCount[diff];
            } 
            prefixSumToCount[currSum]++;
        }
        return count;
    }
};