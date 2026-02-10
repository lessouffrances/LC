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
        return maxPalindrome;
    }
    private:
    int maxLen = 0;
    string maxPalindrome = "";
    void updatePalindrome(int left, int right, const string& s)
    {
        int n = s.length();
        while (left >=0 && right < n && s[left] == s[right]) {
            if (right-left+1 > maxLen) {
                maxPalindrome = s.substr(left, right-left+1);
                maxLen = right-left+1;
            }
            left--;
            right++;
        }
    }
};