class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        vector<int> metric(128, 0);
        int left = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            metric[s[right]]++;
            while (metric[s[right]] == 2) {
                metric[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};