





class Solution 
{
    public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        if (s.length() == 0) return 0;

        int n = s.length();
        int left = 0;
        vector<int>windowCounter(128, 0);
        int numOfUniqueChars = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            if (windowCounter[s[right]] == 0) {
                numOfUniqueChars++;
            } 
            windowCounter[s[right]]++;

            while (numOfUniqueChars > k) {
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