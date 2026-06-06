class Solution 
{
    public:
    // [num1, num2] => queries
    int totalWaviness(int num1, int num2) 
    {
        int totalCount = 0;
        for (int i=num1; i<=num2; i++) {
            totalCount += computeWaviness(i);
        }
        return totalCount;
    }

    private:
    int computeWaviness(int num) 
    {
        // observation!
        if (num < 101) return 0;

        int wavyCount = 0;
        int rightDigit = num % 10;
        num /= 10;
        int middleDigit = num % 10;
        num /= 10;

        while (num) {
            int leftDigit = num % 10;

            bool isPeak = (middleDigit > leftDigit && middleDigit > rightDigit) ? true : false;
            bool isVallet = (middleDigit < leftDigit && middleDigit < rightDigit) ? true : false;

            if (isPeak || isVallet) wavyCount++;

            // update pointer
            rightDigit = middleDigit;
            middleDigit = leftDigit;
            
            num /= 10;
        }
        return wavyCount;
    }
};