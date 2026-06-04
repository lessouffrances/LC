class Solution 
{
    public:
    double myPow(double x, int n)
    {
        if (n == 0) return 1.0;

        int N = n;
        if (N < 0) {
            N = -N;
            x = 1/x;
        } 
        return myPowHelper(x, N);
    }

    private:
    double myPowHelper(double x, long long n)
    {
        if (n == 0) return 1.0;

        double sqrt = myPowHelper(x, n/2);
        if (n % 2 == 0) {
            return sqrt * sqrt;
        } else {
            return sqrt * sqrt * x;
        }
    }
};
