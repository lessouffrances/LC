

class Solution 
{
    public:
    // goal: see sliding window, 
    // we want all the chars in that sliding window 
    // to turn to the char with the maxFreq in the sliding window
    int characterReplacement(string s, int k) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        unordered_map<char, int> windowCounter;
        int maxLen = INT_MIN;
        int left = 0;
        int maxFreq = 0;

        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;
            maxFreq = max( maxFreq, windowCounter[s[right]] );

            // shrink the window
            if (right-left+1-maxFreq > k) {
                if (windowCounter[s[left]] > 0) {
                    windowCounter[s[left]]--;
                    if (windowCounter[s[left]] == 0) 
                    windowCounter.erase(s[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};