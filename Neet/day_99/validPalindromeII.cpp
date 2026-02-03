class Solution 
{
    public:
    bool validPalindrome(string s) 
    {
        if (s.length() == 0) return true;
        int n = s.length();
        int left = 0, right = n-1;

        while (left < right) {
            // if one char does not match, try delete this char
            if (s[left] != s[right]) {
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
            }
            left++;
            right--;
        }
        // all chars are matching
        return true;
    }
    private:
    bool isPalindrome(const string& s, int left, int right)
    {
        if (s.length() == 0) return true;

        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};