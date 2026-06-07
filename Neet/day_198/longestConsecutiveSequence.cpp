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
                // can potentially be a new start for a consecutive nums
                currLen = 1;
                while (numSet.count(num+1)) {
                    num = num+1;
                    currLen++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};