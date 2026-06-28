class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        for (int i=0; i<n; i++) {
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
        while (left >=0 && right < s.length() && s[left] == s[right]) {
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