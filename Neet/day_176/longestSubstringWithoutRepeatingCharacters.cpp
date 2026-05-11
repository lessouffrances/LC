class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        int maxLen = INT_MIN;

        vector<int> windowCounter(128);

        int left = 0;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]-'a']++;
            while (windowCounter[s[right]-'a'] == 2) {
                windowCounter[s[left]-'a']--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};