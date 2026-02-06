








// 38

class Solution 
{
    public:
    int addDigits(int num) 
    {
        if (num>=0 && num<=9) return num;

        int sum = 0;//0 3
        while (num != 0) {
            int digit = num % 10;//8 3
            num /= 10;//3 0
            sum += digit;//8 11
        }

        return addDigits(sum);
    }
};