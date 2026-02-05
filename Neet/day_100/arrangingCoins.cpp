class Solution 
{
    public:
    int arrangeCoins(int n) 
    {
        return arrangeCoinsHelper(1, n);
    }
    private:
    int arrangeCoinsHelper(int level, unsigned long long n) 
    {
        if ( n >= level) {
            n -= level;
            return 1 + arrangeCoinsHelper(level+1, n);
        } else {
            return 0;
        }
    }
};