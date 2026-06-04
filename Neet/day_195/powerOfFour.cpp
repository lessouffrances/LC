class Solution 
{
    public:
    bool isPowerOfFour(int n) 
    {
        if (n <= 0) return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        // the last step is 4 / 4 = 1
        return n == 1;
    }
};