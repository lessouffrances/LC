class Solution 
{
    public:
    int reverseBits(int n)
    {
        string bin = decimalToBin(n);
        reverse(bin.begin(), bin.end());
        return binToDeciaml(bin);
    }

    private:
    int binToDeciaml(string bin)
    {
        int sign = 1;
        if (bin[0] == '+' || bin[0] == '-') {
            sign = (bin[0] == '-') ? -1 : 1;
            // strip the leading sign
            bin = string(bin.begin()+1, bin.end());
        }

        int res = 0;
        int power = 0;
        for (int i=bin.length()-1; i>=0; i--) {
            if (bin[i] == '1') {
                res += pow(2, power);
            }
            power++;
        }
        return sign * res;
    }

    string decimalToBin(int num)
    {
        int sign = 1;
        if (num < 0) {
            sign = -1;
            num = -num;
        }

        string bin = "";
        while (num != 0) {
            bin = to_string(num % 2) + bin;
            num /= 2;
        }

        while (bin.length() < 32) {
            bin = '0' + bin;
        }

        return (sign == 1) ? bin : "-" + bin;
    }
};