class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        int maxLen = 0;
        unordered_map<int, int> windowCounter;
        
        int left = 0;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;

            while (windowCounter[s[right]] == 2) {
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