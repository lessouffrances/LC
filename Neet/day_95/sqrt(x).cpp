class Solution 
{
    public:
    int mySqrt(int x) 
    {
        for (int i=1; i<INT_MAX; i++) {
            if ((long long)i * i == (long long)x) {
                return i;
            } else if ((long long)i * i > (long long)x) {
                return i-1;
            }
        }
        return -1;
    }
};