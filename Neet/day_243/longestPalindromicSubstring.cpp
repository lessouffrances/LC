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
    int maxLen = 0;
    string maxPalin = "";
    void updatePalindrome(int left, int right, const string& s)
    {
        int n = s.length();
        while (left>=0 && right<n && s[left] == s[right]) {
            left--;
            right++;
        }

        left++;
        right--;
        int currLen = right-left+1;
        if (currLen > maxLen) {
            maxLen = currLen;
            maxPalin = s.substr(left, maxLen);
        }
    }
};