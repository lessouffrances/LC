






class Solution 
{
    public:
    int longestSubstring(string s, int k) 
    {
        if (s.length() < k) return 0;
        int n = s.length();

        vector<int>freq(26, 0);
        for (char ch : s) {
            freq[ch-'a']++;
        }

        int maxLen = 0;
        for (int i=0; i<n; i++) {
            if (freq[s[i]] < k) {
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i+1, n-(i+1)+1), k);
                int maxLen = max(left, right);
                return maxLen;
            }
        }
        return n;
    }
};