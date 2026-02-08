class Solution 
{
    public:
    int sumFourDivisors(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int sum = 0;
        for (int num : nums) {
            vector<int> divisors = getDivisors(num);
            if (divisors.size() == 4) {
                sum += accumulate(divisors.begin(), divisors.end(), 0);
            }
        }
        
        return sum;
    }

    private:
    vector<int> getDivisors(int num)
    {
        if (num == 1) return {1};

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