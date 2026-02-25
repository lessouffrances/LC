class Solution 
{
    public:
    int countDigitOne(int n) 
    {
        if (n == 0 || n == 1) return n;
        int res = 0;
        for (int i=0; i<=n; i++) {
            res += countDigitOneHelper(i);
        }
        return res;
    }
    private:
    unordered_map<int, int> memo;
    int countDigitOneHelper(int n)
    {
        // base cases
        if (n == 0 || n == 1) return n;
        if (memo.count(n)) return memo[n];

        int count = 0;
        int originalN = n;
        while (n != 0) {
            int digit = n % 10;
            if (digit == 1) count++;
            n /= 10;
        }
        memo[originalN] = count;
        return count;
    }
};