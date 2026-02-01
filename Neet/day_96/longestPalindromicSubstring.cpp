class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if (s.length() == 0) return "";

        int n = s.length();
        for (int mid=0; mid<n; mid++) {
            updatePalindrome(s, mid, mid, n);
            updatePalindrome(s, mid, mid+1, n);
        }
        return palindrome;
    }
    private:
    string palindrome = "";
    void updatePalindrome(string& s, int left, int right, int n)
    {
        while (left>=0 && right<n && s[left] == s[right]) {
            if (right-left+1 > palindrome.length()) {
                palindrome = s.substr(left, right-left+1);
            }            
            left--;
            right++;
        }
    }
};