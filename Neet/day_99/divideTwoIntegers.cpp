class Solution 
{
    public:
    int divide(int dividend, int divisor) 
    {
        // overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long absDividend = abs((long long) dividend);
        long long absDivisor = abs((long long) divisor);

        long long res = 0;
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            long long multiple = 1;

            while (absDividend >= temp << 1) {
                temp <<= 1;
                multiple <<= 1;
            }

            absDividend -= temp;
            res += multiple;
        }
        
        return isNegative ? -res : res;
    }
};