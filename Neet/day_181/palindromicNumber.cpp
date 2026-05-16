class Solution 
{
    public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;

        string res = "";
        while (x != 0) {
            int digit = x % 10;
            res += digit;
            x /= 10;
        }
        string copyRes = res;
        reverse(res.begin(), res.end());
        return copyRes == res;
    }
};