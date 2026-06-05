class Solution 
{
    public:
    bool isPowerOfTwo(int n) 
    {
        for (int i=0; i<=31; i++) {
            int curr = 1 << i;
            if (curr == n) return true;
            if (curr > n) return false;
        }
        return false;
    }
};