class Solution 
{
    public:
    bool isHappy(int n) 
    {
        if (n == 1) return true;

        unordered_set<int> seen;
        while (!seen.count(n) && n != 1) {
            seen.insert(n);
            n = generateNext(n);
        }
        return n == 1;
    }
    private:
    int generateNext(int n)
    {
        int sum = 0;
        while (n != 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};