class Solution 
{
    public:
    int totalWaviness(int num1, int num2) 
    {
        int totalCount = 0;
        for (int num=num1; num<=num2; num++) {
            totalCount += countWaveOfANumber(num);
        }
        return totalCount;
    }

    private:
    int countWaveOfANumber(int num)
    {
        if (num < 101) return 0;
        int peaks = 0;
        int valleys = 0;

        int rightDigit = num % 10;
        num /= 10;
        int middleDigit = num % 10;
        num /= 10;

        int leftDigit = 0;
        while (num > 0)
        {
            leftDigit = num % 10;
            num /= 10;

            if (middleDigit > leftDigit && middleDigit > rightDigit) peaks++;
            if (middleDigit < leftDigit && middleDigit < rightDigit) valleys++;

            // slide
            // [    l, m, r]
            // [       l, m, r]
            rightDigit = middleDigit;
            middleDigit = leftDigit;
        }
        return peaks + valleys;
    }
};