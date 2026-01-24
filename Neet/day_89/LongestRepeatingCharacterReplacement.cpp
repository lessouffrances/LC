class Solution 
{
    public:
    int characterReplacement(string s, int k)
    {
        if (s.length() == 0) return 0;

        int left = 0;
        int maxLen = INT_MIN;
        int highestFreq = INT_MIN;
        vector<int> windowCounter(26, 0);
        int n = s.length();

        for (int right=0; right<n; right++) {
            windowCounter[s[right]-'A']++;
            highestFreq = max(highestFreq, windowCounter[s[right]-'A']);

            // invalid window
            while ( (right-left+1) - highestFreq > k) {
                windowCounter[s[left]-'A']--;
                left++;
            }

            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};