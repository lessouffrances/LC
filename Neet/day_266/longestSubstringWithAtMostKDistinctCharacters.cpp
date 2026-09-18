class Solution 
{
    public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        int maxLen = 0;

        int left = 0;
        unordered_map<char, int> windowCounter;

        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;

            while (windowCounter.size() > k) {
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
