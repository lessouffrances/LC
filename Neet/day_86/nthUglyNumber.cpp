class Solution 
{
    public:
    int nthUglyNumber(int n) 
    {
        set<long long> uglySet = {1};
        vector<int> primes = {2,3,5};

        long long currentUgly = 1;
        for (int i=0; i<n; i++) {
            currentUgly = *uglySet.begin();
            uglySet.erase(uglySet.begin());

            for (int prime : primes) {
                uglySet.insert(currentUgly * prime);
            }
        }
        return (int)currentUgly;
    }
};