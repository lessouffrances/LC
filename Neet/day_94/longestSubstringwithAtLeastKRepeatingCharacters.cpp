class Solution 
{
    public:
    int longestSubstring(string s, int k) 
    {
        return helper(s, 0, s.length(), k);
    }
    private:
    int helper(string& s, int start, int end, int k) 
    {
        if (end - start < k) return 0;

        // count freq
        vector<int> freq(26, 0);
        for (int i = start; i < end; i++) {
            freq[s[i]-'a']++;
        }

        // find chars that appearings but less than k times
        for (int i=start; i<end; i++) {
            if (freq[s[i]-'a'] > 0 && freq[s[i]-'a'] < k) {
                int next = i+1;
                while (next < end && freq[s[next]-'a'] < k) {
                    next++;
                }

                return max(helper(s, start, i, k), helper(s, next, end, k));
            }
        }
        return end - start;

    }
};