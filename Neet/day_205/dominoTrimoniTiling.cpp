class Solution 
{
    public:
    int numTilings(int n) 
    {
        if (n == 1 || n == 2) return n;

        const long long MOD = 1e9+7;
        vector<long long> f(n+1, 0);
        vector<long long> p(n+1, 0);

        f[1] = 1;
        f[2] = 2;
        p[1] = 0;
        p[2] = 1;

        for (int i=3; i<n+1; i++) {
            p[i] = (p[i-1] + f[i-2]) % MOD;
            f[i] = (f[i-1] + f[i-2] + 2*p[i-1]) % MOD;
        }
        
    }
};