class Solution 
{
    public:
    int nthUglyNumber(int n) 
    {
        set<long long> uglySet =  { 1 };
        set<int> primeSet = {2,3,5};

        int currUgly = 1;
        for (int i=0; i<n; i++) {
            currUgly = *uglySet.begin();
            uglySet.erase(uglySet.begin());
            for (int prime : primeSet) {
                uglySet.insert(currUgly * prime);
            }
        }
        return currUgly;
    }
};