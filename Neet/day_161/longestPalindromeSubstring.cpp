class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if (s.length() == 0) return "";

        for (int i=0; i<s.length(); i++) {
            updatePalindrome(i, i, s);
            updatePalindrome(i, i+1, s);
        }
        return maxPalin;
    }
    private:
    string maxPalin;
    int maxPalinLen = 0;
    void updatePalindrome(int left, int right, const string& s)
    {
        if (s.length() == 0) return;
        int n = s.length();

        while (left>=0 && right<n && s[left] == s[right]) {
            left--;
            right++;
        }
        int len = (right-1)-(left+1)+1;
        if (len > maxPalinLen) {
            maxPalinLen = max(maxPalinLen, len);
            maxPalin = s.substr(left+1, maxPalinLen);
        }
        
    }
};