class Solution 
{
    public:
    int sumFourDivisors(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int res = 0;
        for (int& num : nums) {
            vector<int> divisors = findDivisors(num);
            if (divisors.size() == 4) {
                res += accumulate(divisors.begin(), divisors.end(), 0);
            } 
        }
        return res;
    }
    private:
    vector<int> findDivisors(int num)
    {
        vector<int> res;
        int sqrtNum = sqrt(num);
        for (int i=1; i<=sqrtNum; i++) {
            if (num % i == 0) {
                res.push_back(i);
                if (i != num / i) {
                    res.push_back(num / i);
                }
            }
        }
        return res;
    }
};