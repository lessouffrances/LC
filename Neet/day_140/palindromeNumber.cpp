class Solution 
{
    public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;

        string s = "";
        while (x != 0) {
            int digit = x % 10;
            s += digit + '0';
            x /= 10;
        }
        
        string copy = s;
        reverse(copy.begin(), copy.end());
        return copy == s;
    }
};