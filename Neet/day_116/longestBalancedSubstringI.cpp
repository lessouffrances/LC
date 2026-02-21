class Solution 
{
    public:
    int longestBalanced(string s) 
    {
        // brute-force substrings
        int n = s.length();
        int maxLen = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (isBalanced(s, i, j)) {
                    maxLen = max(maxLen, sub.length());
                }
            }
        }
        return maxLen;
    }
    private:
    bool isBalanced(const stringf& s, int left, int right)
    {
        unordered_map<char, int> freq;
        for (int i=left; i<=right; i++) {
            freq[s[i]]++;
        }

        int unique = freq.begin()->second;
        for (auto& [ch, count] : freq) {
            if (count != unique) return false;
        }
        return true;
    }
};