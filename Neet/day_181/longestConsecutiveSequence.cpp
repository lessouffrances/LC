


class Solution 
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        unordered_set<int> numsSet(nums.begin(), nums.end());
        int length = 0;
        int maxLen = 0;
        for (int num : numsSet) {
            if (!numsSet.count(num-1)) {
                length = 1;
                while (numsSet.count(num+1)) {
                    num = num+1;
                    length++;
                }
                maxLen = max(maxLen, length);
            }
        } 
        return maxLen;
    }
};