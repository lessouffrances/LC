class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if (s.length() <= 1) return s;
        int n = s.length();

        for (int mid=0; mid<n; mid++) {
            updatePalindromes(mid, mid, s);
            updatePalindromes(mid, mid+1, s);
        }
        return maxPalindrome;
    }

    private:
    int maxLen;
    string maxPalindrome;
    void updatePalindromes(int left, int right, const string& s)
    {
        int n = s.length();
        while (left>=0 && right<n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
                maxPalindrome = string(s.begin()+left, s.begin()+right+1);
            }
            left--;
            right++;
        }

    }
};