



class Solution 
{
    public:
    bool isPowerOfTwo(int n) 
    {
        if (n <= 0) return false;

        for (int i=0; i<=30; i++) {
            int comp = 1 << i;
            if (comp == n) return true;
        }
        return false;
    }
};