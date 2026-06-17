class Solution 
{
    public:
    int countPrimes(int n) 
    {
        if (n < 2) return 0;

        vector<bool> sieve(n, true);
        sieve[0] = false;
        sieve[1] = false;

        for (int i=2; i*i < n; i++) {
            if (sieve[n]) {
                for (int j=i*i; j<n; j+=i) {
                    sieve[j] = false;
                }
            }
        }
        return count(sieve.begin(), sieve.end(), true);
    }
};