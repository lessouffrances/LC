class Solution 
{
    public:
    int countSubstrings(string s) 
    {
        for (int mid=0; mid<s.length(); mid++) {
            updatePalindrome(s, mid, mid);
            updatePalindrome(s, mid, mid+1);
        }
        return res;
    }
    private:
    int res = 0;
    void updatePalindrome(string& s, int left, int right)
    {
        while (left >= 0 && right < s.length()) {
            if (s[left] == s[right]) {
                res++;
                left--;
                right++;
            } else {
                break;
            }
        }
    }
};