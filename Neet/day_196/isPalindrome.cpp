class Solution 
{
    public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;

        long long res = 0;
        int copyX = x;
        // 323
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == copyX;
    }
};