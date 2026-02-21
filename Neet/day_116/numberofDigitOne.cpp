class Solution 
{
    public:
    int countDigitOne(int n) 
    {
        if (memo.count(n)) return memo[n];
        return countDigitOneHelper(n);
    }
    private:
    // 1  → one 1
    // 10 → one 1
    // 11 → two 1s
    // 12 → one 1
    // 13 → one 1
    unordered<int, int> memo;
    int countDigitOneHelper(int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;

        memo[0] = 0;
        memo[1] = 1;

        int count = 0;
        while (n != 0) {
            int digit = n % 10;
            if (digit == 1) count++;
            n /= 10;
        }
        memo[n] = count;
        return count;
    }
};