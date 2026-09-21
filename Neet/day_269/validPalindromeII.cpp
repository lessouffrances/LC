

class Solution 
{
    public:
    bool validPalindrome(string s) 
    {
        int n = s.length();

        int left = 0, right = n-1;
        while (left < right) {
            if (s[left] != s[right]) {
                return checkPalindrome(left+1, right, s) || checkPalindrome(left, right-1, s);
            }
            left++;
            right--;
        }
        return true;
    }

    private:
    bool checkPalindrome(int left, int right, const string& s) 
    {
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};