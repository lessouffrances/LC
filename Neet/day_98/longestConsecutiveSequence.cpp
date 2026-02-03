class Solution 
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        unordered_set<int> numsSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : numsSet) {
            if (!numsSet.count(num-1)) {
                int currNum = num;
                int currLen = 1;

                while (numsSet.count(currNum+1)) {
                    currNum++;
                    currLen++;
                }

                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};