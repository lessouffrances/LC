class Solution 
{
    public:
    int longestSubstring(string s, int k) 
    {
        if (s.length() < k) return 0;
        int n = s.length();

        unordered_map<int, int> freq;
        for (char ch : s) freq[ch]++;
        int maxLen = 0;

        for (int i=0; i<n; i++) {
            if (freq[s[i]] < k) {
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i+1), k);
                maxLen = max(left, right);
                return maxLen;
            }
        }
        return n;
    }
};