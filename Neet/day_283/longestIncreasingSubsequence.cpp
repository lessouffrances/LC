
// the idea
// each num can be seen as a IS len of 1

class Solution 
{
    public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        unordered_map<int, int> lookup; // { index, LIS }
        lookup[0] = 1;
        int maxLen = 1;

        for (int i=1; i<n; i++) {
            // every num is a LIS of len 1
            lookup[i] = 1;
            int currNum = nums[i];
            for (auto& [idx, LIS] : lookup) {
                int prevNum = nums[idx];
                if (currNum > prevNum) {
                    lookup[i] = max(lookup[i], 1+LIS);
                    maxLen = max(maxLen, lookup[i]);
                }
            }
        }
        return maxLen;
    }
};