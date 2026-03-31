


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

        // the number n was seen
        return n == 1;
    }

    private:
    int generateNext(int n) {
        
        int next = 0;
        while (n != 0) {
            int digit = n % 10;
            next += digit * digit;
            n /= 10;
        }
        return next;
    }
};