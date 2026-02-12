






class Solution 
{
    public:
    bool isHappy(int n) 
    {
        if (n == 1) return true;

        unordered_set<int> seen;
        while (!seen.count(n) && n != 1) {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
    private:
    int getNext(int n)
    {
        int res = 0;
        while (n != 0) {
            int digit = n % 10;
            n /= 10;
            res += digit * digit;
        }
        return res;
    }
};
