// the frequency of each char in this substring is greater than or equal to k.
// given this, find the max len of the substring

class Solution 
{
    public:
    int longestSubstring(string s, int k) 
    {
        if (s.length() < k) return 0;
        int n = s.length();

        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch-'a']++;
        }

        int maxLen = 0;
        for (int i=0; i<n; i++) {
            if (freq[s[i]-'a'] < k) {
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i+1), k);
                int maxLen = max(left, right);
                return maxLen;
            }
        }
        return n;
    }
};