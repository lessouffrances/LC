class Solution 
{
    public:
    bool isPowerOfTwo(int n) 
    {
        if (n <= 0) return false;
        for (int power = 0; power <= 30; power++) {  // 2^30 > INT_MAX, so 30 is enough
            int comp = 1 << power;
            if (comp == n) return true; 
        }
        return false;
    }
};