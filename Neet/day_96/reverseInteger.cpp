











// x = -123

class Solution 
{
    public:
    int reverse(int x) 
    {
        int res = 0; //0
        while (x != 0) { //x=-123 x=-12 x=-1
            int digit = x % 10; //-3 -2 -1
            x /= 10; //-12 -1 0

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit == 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit == -8)) {
                return 0;
            }

            res = res * 10 + digit;//-3 -3*10+(-2)=-32 -32*10+(-1) = -321
        }

        return res;
    }
};