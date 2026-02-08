class Solution 
{
    public:
    bool checkPerfectNumber(int num) 
    {
        if (num == 1) return false;

        vector<int> divisors = getDivisors(num);
        return num == accumulate(divisors.begin(), divisors.end(), 0);
    }
    private:
    vector<int> getDivisors(int num) 
    {
        vector<int> res;
        int sqrtNum = sqrt(num);

        for (int i=1; i<=sqrtNum; i++) {
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