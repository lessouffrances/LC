class Solution 
{
    public:
    int countCommas(int n) 
    {
        if (n < 1000) return 0;
        // 1,000  all 4-digit numbers have 1 comma, 4%3 = 1
        // 12,000
        // 122,000
        // 1,122,000 
        int res = 0;
        for (int num = 1000; num<=n; num++) {
            res += countCommasForSingleNumber(num);
        }
        return res;
    }

    private:
    int countCommasForSingleNumber(int number)
    {
        string numStr = to_string(number);
        int mod = numStr.length() % 3;
        int division = numStr.length() / 3;

        int res = 0;
        if (mod == 0) {
            res = division-1;
        } else {
            res = division;
        }
        return res;
    }
};