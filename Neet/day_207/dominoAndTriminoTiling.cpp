class Solution 
{
    public:
    int numTilings(int n) 
    {
        if (n == 1 || n == 2) return n;
        const long long MOD = 1e9 + 7;

        vector<int> f(n+1, 0);
        vector<int> p(n+1, 0);

        // base cases
        f[1] = 1;
        f[2] = 2;
        p[1] = 0;
        p[2] = 1; // only count one orientation

        for (int k=3; k<n+1; k++) {
            p[k] = (p[k-1]+f[k-2]) % MOD;
            f[k] = (f[k-1]+f[k-2]+2*p[k-1]) % MOD;
        }
        return f[n];
    }
};