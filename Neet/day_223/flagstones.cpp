class Solution 
{
    public:
    int flagstones(int m, int n, int a) 
    {
        int mRes = m / a;
        int nRes = n / a;
    
        int res = mRes * nRes;
        if (mRes % a != 0) {
            res += n;
        }
        if (nRes % a != 0) {
            res += m;
        }
        return res;
    }
};