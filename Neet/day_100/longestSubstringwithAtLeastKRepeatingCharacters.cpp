class Solution 
{
    public:
    int longestSubstring(string s, int k) 
    {
        return helper(s, 0, s.length(), k);
    }
    private:
    int helper(const string& s, int start, int end, int k)
    {
        if (end - start + 1 < k) return 0;

        vector<int> freq(26, 0);
        for (int i=start; i<end; i++) {
            freq[s[i]-'a']++;
        }

        // check if the entire string is valid
        bool isValid = true;
        for (int i=start; i<end; i++) {
            if (freq[s[i]-'a'] > 0 && freq[s[i]-'a'] < k) {
                isValid = false;
                break;
            }
        }
        if (isValid) return end - start;

        // otherwise, split on chars that appears < k times;
        int maxLen = 0;
        int left = start;
        for (int i=start; i<end; i++) {
            if (freq[s[i]-'a'] > 0 && freq[s[i]-'a'] < k) {
                maxLen = max(maxLen, helper(s, left, i, k));
                left = i+1;
            }
        }

        maxLen = max(maxLen, helper(s, left, end, k));
        return maxLen;
    }
};