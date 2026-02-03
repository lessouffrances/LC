






// x = 2.00000, n = 10

// N = 10
// half = powHelper(2.0, 5)



// x = 2.10000, n = 3
// x = 2.00000, n = -2


class Solution 
{
    public:
    double myPow(double x, int n) 
    {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return powHelper(x, N);
    }
    private:
    double powHelper(double x, long long n)
    {
        if (n == 0) return 1.0;

        double half = powHelper(x, n/2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};