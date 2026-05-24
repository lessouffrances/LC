class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();
        for (int i=0; i<n; i++) {
            updatePalindrome(i, i, s);
            updatePalindrome(i, i+1, s);
        }
        return palindrome;
    }
    private:
    string palindrome = "";
    int maxLen = 0;
    void updatePalindrome(int left, int right, string s)
    {
        int n = s.length();
        while (left>=0 && right<n && s[left] == s[right]) {
            left--;
            right++;
        }

        int currLen = (right-1)-(left+1)+1;
        if (currLen > maxLen) {
            maxLen = currLen;
            palindrome = s.substr(left+1, currLen);
        }
    }
};