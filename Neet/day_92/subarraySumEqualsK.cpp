class Solution 
{
    public:
    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;

        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;

            if (prefixSumFreq.count(sum - k)) {
                count += prefixSumFreq[sum-k];
            }
            prefixSumFreq[sum]++;
        }
        return count;
    }
};