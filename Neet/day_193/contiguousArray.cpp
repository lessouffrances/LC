class Solution 
{
    public:
    int findMaxLength(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        unordered_map<int, int> prefixSumToIdx;
        int n = nums.size();
        prefixSumToIdx[0] = -1;

        int prefixSum = 0;
        int maxLen = 0;
        for (int i=0; i<n; i++) {
            prefixSum += nums[i] == 1 ? 1 : -1;
            if (prefixSumToIdx.count(prefixSum)) {
                maxLen = max(maxLen, i - prefixSumToIdx[prefixSum]);
            } else {
                prefixSumToIdx[prefixSum] = i;
            }
            
        }
        return maxLen;
    }
};