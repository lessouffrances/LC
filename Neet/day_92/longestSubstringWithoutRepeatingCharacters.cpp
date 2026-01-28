class Solution 
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        // store the last seen pos of this cahr
        vector<int> lastSeen(128, 0);

        int left = 0;
        int maxLen = INT_MIN;
        for (int right=0; right<n; right++) {
            char ch = s[right];

            // there are duplicates of ch in the current window
            if (lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1; // update window
            }

            lastSeen[ch] = right;
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};