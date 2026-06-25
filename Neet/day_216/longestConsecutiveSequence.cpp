class Solution 
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int currLen = 0;
        int maxLen = 0;
        for (int num : numSet) {
            if (!numSet.count(num-1)) {
                currLen = 1;
                while (numSet.count(num+1)) {
                    num = num+1;
                    currLen++;
                }
                maxLen = max(currLen, maxLen);
            }
        }
        return maxLen;
    }
};