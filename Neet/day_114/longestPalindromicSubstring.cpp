class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();
        for (int i=0; i<n; i++) {
            updatePalindrome(i, i+1, s);
            updatePalindrome(i, i, s);
        }
        return maxPalindrome;
    }
    private:
    int maxLen = 0;
    string maxPalindrome = "";
    void updatePalindrome(int left, int right, const string& s) {
        int n = s.length();
        while (left>=0 && right<n && s[left] == s[right]) {
            if (right-left+1 > maxLen) {
                maxLen = right-left+1;
                maxPalindrome = s.substr(left, maxLen);
            }
            left--;
            right++;
        }
    }
};