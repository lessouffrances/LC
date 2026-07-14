class Solution 
{
    public:
    bool isHappy(int n) 
    {
        unordered_set<int> seen;
        while (!seen.count(n) && n != 1) {
            seen.insert(n);
            n = isHappyNext(n);
        }
        return n == 1;
    }

    private:
    int isHappyNext(int n)
    {
        int res = 0;
        while (n) {
            int digit = n % 10;
            res += digit * digit;
            n /= 10;
        }
        return res;
    }
};