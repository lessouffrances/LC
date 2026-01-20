class Solution 
{
    public:
    bool isUgly(int n) 
    {
        if (n <=0) return false;

        unordered_set<int> primes = {2, 3, 5};
        for (int prime : primes) {
            while (n % prime == 0) {
                n = n / prime;
            }
        }
        return n == 1;
    }
};
