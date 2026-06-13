class Solution 
{
    public:
    int numTilings(int n) 
    {
        if (n == 1) return 1;
        if (n == 2) return 2;
        const long long MOD = 1e9 + 7;
        vector<long long> f(n+1, 0);
        vector<long long> p(n+1, 0);
        
        // base cases
        f[1] = 1;
        f[2] = 2;
        p[1] = 0;
        p[2] = 1;
        
        for (int k = 3; k <= n; k++) {
            p[k] = (p[k-1] + f[k-2]) % MOD;
            f[k] = (f[k-1] + f[k-2] + 2*p[k-1]) % MOD;
        }
        return f[n];
    }
};