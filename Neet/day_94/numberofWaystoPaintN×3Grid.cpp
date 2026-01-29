class Solution 
{
    public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        // Two patterns for a row:
        // ABA: 3 colors alternating (like RYR, YRY, etc.) - 6 combinations
        // ABC: 3 different colors (like RYG, GYR, etc.) - 6 combinations
        
        long long aba = 6;  // Count of ABA patterns
        long long abc = 6;  // Count of ABC patterns
        
        for (int i = 2; i <= n; i++) {
            long long newAba = (aba * 3 + abc * 2) % MOD;
            long long newAbc = (aba * 2 + abc * 2) % MOD;
            
            aba = newAba;
            abc = newAbc;
        }
        
        return (aba + abc) % MOD;
    }
};