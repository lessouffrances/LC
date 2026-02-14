class Solution 
{
    public:
    int reverseBits(int n)
    {
        string bin = decimalToBinary(n);
        reverse(bin.begin(), bin.end());
        return binaryToDecimal(bin);
    } 
    private:
    int binaryToDecimal(string bin)
    {
        if (bin.length() == 0) return 0;

        bool isNegative = bin[0] == '-';
        if (isNegative) bin = bin.substr(1);
        int n = bin.length();
        int power = 0;
        int decimal = 0;
        for (int i=n-1; i>=0; i--) {
            if (bin[i] == '1') {
                decimal += pow(2, power);
            }
            power++;
        }
        return isNegative ? -decimal : decimal;
    }
    string decimalToBinary(int n)
    {
        string bin = "";
        if (n == 0) bin = "0";
        bool isNegative = n < 0;
        unsigned int num = isNegative ? -n : n;
        while (n > 0) {
            bin += (n % 2) + '0';
            n /= 2;
        }
        reverse(bin.begin(), bin.end());
        while (bin.length() < 32) {
            bin = '0' + bin;
        }
        if (isNegative) bin = '-' + bin;
        return bin;
    }
};