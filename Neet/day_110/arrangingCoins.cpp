



class Solution 
{
    public:
    int arrangeCoins(int n) 
    {
        return arrangeCoinsHelper(n, 1);
    }
    private:
    int arrangeCoinsHelper(int n, int level) 
    {
        // if the coins are enough for this level
        if (n >= level) {
            return 1 + arrangeCoinsHelper(n - level, level+1);
        } else {
            return 0;
        }
    }
};