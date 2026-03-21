

// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() == 0) return 0;

        // this questions contains both lower nad upper case
        vector<int> windowCounter(128, 0);
        int left = 0;
        int maxLen = 0;
        for (int right=0; right<s.length(); right++) {
            windowCounter[s[right]]++;
            // shift left until the s[right] is not repeated
            while (windowCounter[s[right]] == 2) {
                windowCounter[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};