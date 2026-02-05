class Solution 
{
    public:
    int characterReplacement(string s, int k) 
    {
        if (s.length() == 0) return 0;

        int n = s.length();
        int maxLen = 0;
        vector<int> windowCounter(26, 0);
        int maxFreq = 0;

        int left = 0;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]-'A']++;
            maxFreq = max(maxFreq, windowCounter[s[right]-'A']);

            // if the minimum operations needed in the current window > k, shrink the window
            while (right-left+1-maxFreq > k) {
                if (windowCounter[s[left]-'A'] > 0 ) {
                    windowCounter[s[left]-'A']--;
                    left++;
                }
            }

            maxLen = max(maxLen, right-left+1);
        }

        return maxLen;
    }
};