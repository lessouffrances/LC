















class Solution 
{
    public:
    bool checkPerfectNumber(int num) 
    {
        if (num <= 0 || num == 1) return false;
        vector<int> divisors = getDivisors(num);
        return num == accumulate(divisors.begin(), divisors.end(), 0);
    }
    private:
    vector<int> getDivisors(int num)
    {
        int sqrtNum = sqrt(num);

        vector<int> res;
        for (int i=1; i<=sqrtNum; i++) {
            // i is a divisor of num
            if (num % i == 0) {
                res.push_back(i);
                if (i != num / i && num / i != num) {
                    res.push_back(num / i);
                }
            }
        }
        return res;
    }
};