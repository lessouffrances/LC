class Solution 
{
    public:
    int sumFourDivisors(vector<int>& nums) 
    {
        int totalSum = 0;

        for (int num : nums) {
            int sum = getSumIfFourDivisors(num);
            totalSum += sum;
        }
        return totalSum;
    }
    private:
    int getSumIfFourDivisors(int num)
    {
        int count = 0;
        int sum = 0;
        int sqrtNum = sqrt(num);

        for (int i=1; i<=sqrtNum; i++) {
            if (num % i == 0) {
                count++;
                sum += i;

                if (i != num / i) {
                    count++;
                    sum += num / i;
                }
                if (count > 4) {
                    return 0;
                }
            }
        }
        return (count == 4) ? sum : 0;
    }
};