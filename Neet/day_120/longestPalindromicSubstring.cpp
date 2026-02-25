class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if (s.length() == 0) return "";
        if (s.length() == 1) return s;

        int n = s.length();
        
        for (int i=0; i<n; i++) {
            updatePalindrome(i, i, s);
            updatePalindrome(i, i+1, s);
        }
        return maxPalin;
    }
    private:
    string maxPalin = "";
    int maxLen;
    void updatePalindrome(int left, int right, const string& s)
    {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right-left+1 > maxLen) {
                maxLen = right-left+1;
                maxPalin = s.substr(left, maxLen);
            }
            left--;
            right++;
        }
    }
};