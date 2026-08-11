class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.length();
        int left = 0;
        vector<int> counter(128, 0);
        int maxLen = 0;

        for (int right=0; right<n; right++) {
            counter[s[right]]++;
            while (counter[s[right]] == 2) {
                counter[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};