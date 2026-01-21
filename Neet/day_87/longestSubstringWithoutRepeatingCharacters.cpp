class Solution 
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0) return 0;
        // store the pos of last seen this char
        vector<int> lastSeen(128, -1);
        int left = 0;
        int n = s.length();
        int maxLen = 0;

        for (int right=0; right<n; right++) {
            char ch = s[right];

            if (lastSeen[ch] >= left) {
                left = lastSeen[ch]+1;
            }
            lastSeen[ch] = right;
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};