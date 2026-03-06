class Solution 
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        
        unordered_set<int>numSet(nums.begin(), nums.end());

        // look for if the (num-1) exists in numSet
        int length = 0;
        int maxLen = 0;
        // if iterate the vector, it will give TLE
        for (int num : numSet) {

            if (!numSet.count(num-1)) {
                // start a new record
                length = 1;
                // while loop counts the length
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