






// Time: O(log N)
// Space: O(log N)
class Solution 
{
    public:
    double myPow(double x, int n)
    {
        // base case, any number to the power 0 is 1
        if (n == 0) return 1.0;

        long long N = n;
        if (n < 0) {
            x = 1/x;
            N = - (long long)n;
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