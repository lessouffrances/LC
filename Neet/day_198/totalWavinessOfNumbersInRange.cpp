class Solution 
{
    public:
    int totalWaviness(int num1, int num2) 
    {
        int waviness = 0;
        for (int i=num1; i<=num2; i++) {
            waviness += countWaviness(i);
        }
        return waviness;
    }

    private:
    int countWaviness(int num)
    {
        if (num < 101) return 0;

        int rightDigit = num % 10;
        num /= 10;
        int middleDigit = num % 10;
        num /= 10;

        int count = 0;
        while (num) {
            int leftDigit = num % 10;

            bool isPeak = (middleDigit>leftDigit && middleDigit>rightDigit) ? true : false;
            bool isValley = (middleDigit<leftDigit && middleDigit<rightDigit) ? true : false;

            if (isPeak || isValley) count++;

            // shift the left, mid, right to the left by one
            //     left, mid, right
            rightDigit = middleDigit;
            middleDigit = leftDigit;
            num /= 10;
        }
        return count;
    }
};