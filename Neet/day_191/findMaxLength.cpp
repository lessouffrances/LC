

// if prefixSum[i] == prefixSum[j], the subarray (j, i] has equal 0s and 1s.
class Solution 
{
    public:
    int findMaxLength(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        unordered_map<int, int> firstSeen; // prefixSum -> first index seen
        firstSeen[0] = -1;

        int prefixSum = 0;
        int maxLen = 0;

        for (int i=0; i<n; i++) {
            prefixSum += (nums[i] == 1) ? 1 : -1;

            if (firstSeen.count(prefixSum)) {
                maxLen = max(maxLen, i - firstSeen[prefixSum]);
            } else {
                firstSeen[prefixSum] = i;
            }
        }
        return maxLen;
    }
};