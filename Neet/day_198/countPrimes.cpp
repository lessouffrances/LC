class Solution 
{
    public:
    int countPrimes(int n) 
    {
        if (n < 2) return 0;

        vector<bool> sieve(n, false);
        sieve[0] = false;
        sieve[1] = false;

        // iterate thru all sqrt of n
        for (int i=2; i*i<n; i++) {
            if (sieve[i]) {
                for (int j=i*i; j<n; j+=i) {
                    sieve[i] = false;
                }
            }
        }
        return count(sieve.begin(), sieve.end(), true);
    }
};