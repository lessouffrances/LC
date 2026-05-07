// T: O(N)
// S: O(1)

class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.empty()) return 0;
        int n = s.length();
        vector<int> windowCounter(128);
        int maxLen = 0;
        
        int left = 0;
        for (int right=0; right<n; right++) {
            windowCounter[s[right]]++;
            while (windowCounter[s[right]] == 2) {
                windowCounter[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};