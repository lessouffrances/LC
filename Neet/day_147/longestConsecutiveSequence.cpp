

// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        unordered_set<int>numSet(nums.begin(), nums.end());
        int length = 0;
        int maxLen = 0;

        for (int num : numSet) {
            // this is a start point
            if (!numSet.count(num-1)) {
                length = 1;
                while (numSet.count(num+1)) {
                    length++;
                    num = num+1;
                }
                maxLen = max(maxLen, length);
            }
        }
        return maxLen;
    }
};