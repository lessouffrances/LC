class Solution 
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        unordered_set<int> numsSet(nums.begin(), nums.end());
        int maxLen = 0;
        int currLen = 0;

        for (int num : numsSet) {
            if (!numsSet.count(num-1)) {
                currLen = 1;
                while (numsSet.count(num+1)) {
                    num = num+1;
                    currLen++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};