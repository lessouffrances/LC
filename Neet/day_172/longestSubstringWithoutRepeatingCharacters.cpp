class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        vector<int> windowMetric(128);

        int left = 0;
        int maxLen = 0;
        for (int right=0; right<n; right++) {
            windowMetric[s[right]]++;
            while (windowMetric[s[right]] == 2) {
                windowMetric[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};