class Solution 
{
    public:
    // prefixSum[0...i] + subarraySum = prefixSum[0...j], i<=j
    // we know, subarraySum is k and prefixSum[0...j] is currSum,
    // diff = prefixSum[0...i] can be found in the map, incrememnt count
    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;
        int currSum = 0;
        int count = 0;

        for (int i=0; i<n; i++) {
            currSum += nums[i];
            int diff = currSum - k;
            if (prefixSumFreq.count(diff)) {
                count += prefixSumFreq[diff];
            } 
            prefixSumFreq[currSum]++;
        }
        return count;
    }
};