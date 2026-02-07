















class Solution 
{
    public:
    int arrangeCoins(int n) 
    {

    }
    private:
    int arrangeCoinsHelper(int level, int n)
    {
        if (n >= level) {
            n -= level;
            return 1 + arrangeCoinsHelper(level+1, n);
        } else {
            return 0;
        }
    }
};