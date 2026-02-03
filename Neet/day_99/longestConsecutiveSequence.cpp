class Solution 
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        int maxLen = 0;
        for (int num : numSet) {
            if (!numSet.count(num-1)) {
                int currNum = num;
                int currLen = 1;

                while (numSet.count(currNum+1)) {
                    currLen++;
                    currNum++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};