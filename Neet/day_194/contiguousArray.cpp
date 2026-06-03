

// if prefixSum[i] == prefixSum[j], then the subarray[i, j)...
class Solution 
{
    public:
    int findMaxLength(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = -1;

        int currSum = 0;
        int maxLen = 0;
        for (int i=0; i<nums.size(); i++) {
            currSum += (nums[i] == 1) ?  1 : -1;
            if (prefixSumMap.count(currSum)) {
                maxLen = max(maxLen, i-prefixSumMap[currSum]);
            } else {
                prefixSumMap[currSum] = i;
            }
        }
        return maxLen;
    }
};