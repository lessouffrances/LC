class Solution 
{
    public:
    bool checkPerfectNumber(int num) 
    {
        if (num == 1) return false;

        vector<int> divisors = findDivisors(num);
        return num == accumulate(divisors.begin(), divisors.end(), 0);
    }
    private:
    vector<int> findDivisors(int num)
    {
        vector<int> res;
        int sqrtNum = sqrt(num);

        for (int i=1; i<=sqrtNum; i++) {
            // i is a divisor of num
            if (num % i == 0) {
                res.push_back(i);

                if (i != 1 && i != num / i) {
                    res.push_back(num / i);
                }
            }
        }

        return res;
    }
};