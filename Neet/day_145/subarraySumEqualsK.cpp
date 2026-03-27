



// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = 1;
        int currSum = 0;
        int res = 0;
        for (int i=0; i<n; i++) {
            currSum += nums[i];
            int diff = currSum - k;
            if (prefixSumMap.count(diff)) {
                res += prefixSumMap[diff];
            }
            prefixSumMap[currSum]++;
        }
        return res;
    }
};