















class Solution 
{
    public:
    bool isHappy(int n) 
    {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getDigitSum(n);
        }

        return n == 1;
    }
    private:
    int getDigitSum(int n)
    {
        int sum = 0;
        while (n != 0) {
            int digit = n % 10;
            n /= 10;
            sum += digit * digit;
        } 
        return sum;
    }
};