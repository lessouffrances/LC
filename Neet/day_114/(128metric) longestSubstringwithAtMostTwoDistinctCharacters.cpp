


class Solution 
{
    public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        vector<int>windowCounter(128);
        int left = 0;
        int numOfUniqueChars = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            if (windowCounter[s[right]] == 0) {
                numOfUniqueChars++;
            }
            windowCounter[s[right]]++;
            while (numOfUniqueChars > 2) {
                windowCounter[s[left]]--;
                if (windowCounter[s[left]] == 0) {
                    numOfUniqueChars--;
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};