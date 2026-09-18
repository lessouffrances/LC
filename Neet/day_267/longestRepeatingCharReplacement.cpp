class Solution 
{
    public:
    int characterReplacement(string s, int k) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        unordered_map<char, int> windowCounter;
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;
            maxFreq = max(maxFreq, windowCounter[s[right]]);

            // invalid windows
            // we can change at most k chars
            while (right-left+1-maxFreq > k) {
                windowCounter[s[left]]--;
                if (windowCounter[s[left]] == 0) {
                    windowCounter.erase(s[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};