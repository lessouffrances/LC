class Solution 
{
    public:
    int addDigits(int num) 
    {
        if (num >=0 && num <= 9) return num;
        
        int sum = 0; //0
        while (num != 0) {
            int digit = num % 10; //6 5 4 
            num /= 10; //145 14 1
            sum += digit; //6 11 15
        }

        return addDigits(sum + num);

    }
};