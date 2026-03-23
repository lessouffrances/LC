

// Time: O(N)
// Space: O(N)
class Solution 
{
    public:
    // subarray that summed up to k
    // diff = prefixSum[0..i] - k
    // why? 
    // [1,2,3] k = 3;
    // prefixSumCounter: { {0,1}, {1,1}, {3,1}, {6,1} }
    //             DIFF            -2     0      3

    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int res = 0;

        unordered_map<int, int> prefixSumCounter;
        prefixSumCounter[0] = 1;

        int currPrefixSum = 0;
        for (int num : nums) {
            currPrefixSum += num;
            int diff = currPrefixSum - k;
            if (prefixSumCounter.count(diff)) {
                res += prefixSumCounter[diff];
            }
            prefixSumCounter[currPrefixSum]++;
        }
        return res;
    }
};