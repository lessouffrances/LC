class Solution 
{
    public:
    bool isPalindrome(string s) 
    {
        if (s.length() == 0 || s.length() == 1) return true;
        int n = s.length();

        int left = 0, right = n-1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            if (tolower(s[left]) == tolower(s[right])) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};