class Solution 
{
    public:
    int sumFourDivisors(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int totalSum = 0;
        for (int num : nums) {
            totalSum += getSumIfFourDivisors(num);
        }

        return totalSum;
    }
    int getSumIfFourDivisors(int num) 
    {
        int sum = 0;
        int count = 0;
        int sqrtNum = sqrt(num);

        for (int i=1; i<=sqrtNum; i++) {
            // if i is a divisor of num
            if (num % i == 0) {
                count++;
                sum += i;

                if (i != num / i) {
                    count++;
                    sum += num / i;
                }

                if (count > 4) return 0;
            }
        }
        return (count == 4) ? sum : 0;
    }
};