class Solution 
{
    public:
    int reverseBits(int n)
    {
        string bin = decimalToBinary(n);
        reverse(bin.begin(), bin.end());
        int res = binaryToDecimal(bin);
        return res;
    }

    private:
    int binaryToDecimal(string bin)
    {
        if (bin.length() == 0) return 0;

        int sign = bin[0] == '-' ? -1 : 1;
        if (sign == -1) {
            bin = bin.substr(1);
        }

        int n = bin.length();
        int res = 0;
        int power= 0;
        // iterate from smallest bit 
        // iterate from the right
        for (int i=n-1; i>=0; i--) {
            if (bin[i] == '1') {
                res += pow(2, power);
            }
            power++;
        }
        return sign * res;
    }

    string decimalToBinary(int n)
    {
        string bin = "";
        bool isNegative = (n < 0) ? true : false;
        if (isNegative) {
            n = -n;
        }

        while (n != 0) {
            bin = to_string(n % 2) + bin;
            n /= 2;
        }
        while (bin.length() < 32) {
            bin = '0' + bin;
        }
        return isNegative ? "-"+bin : bin;
    }
};

// n = 10
// n = 1
// bin = 1010
