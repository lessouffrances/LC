class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();

        for (int mid=0; mid<n; i++) {
            updateMaxLenPalindrome(mid, mid, s);
            updateMaxLenPalindrome(mid, mid+1, s);
        }
        return maxLenPalindrome;
    }
    
    private:
    int maxLen = INT_MIN;
    string maxLenPalindrome;
    void updateMaxLenPalindrome(int left, int right, const string& s)
    {
        int n = s.length();
        while (left >=0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLenPalindrome = s.substr(s.begin()+left, s.begin()+right+1);
                maxLen = currLen;
            }
            left--;
            right++;
        }
    }
};