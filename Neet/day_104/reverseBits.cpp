




class Solution 
{
    public:
    int reverseBits(int n) 
    {
        // convert to binary Form
        string bin = decimalToBinary(n);
        reverse(bin.begin(), bin.end());
        int res = binaryToDecimal(bin);
        return res;
    }
    private:
    int binaryToDecimal(string bin)
    {
        if (bin.length() == 0) return 0;

        // check if signed
        bool isNegative = false;
        if (bin[0] == '-') {
            isNegative = true;
            bin = bin.substr(1);
        }

        // traverse from right to left
        int power = 0;
        int decimalForm = 0;
        for (int i=bin.length()-1; i>=0 ;i--) {
            if (bin[i] == '1') {
                decimalForm += pow(2, power);
            }
            power++; // always increment the power
        }
        return isNegative ? -decimalForm : decimalForm;
    }

    string decimalToBinary(int num)
    {
        bool isNegative = num < 0;
        unsigned int n = isNegative ? -num : num;

        string binaryForm = "";
        while (n > 0) {
            binaryForm += (n % 2) + '0';
            n /= 2;
        }
        reverse(binaryForm.begin(), binaryForm.end());

        // Pad with leading zeros to make it 32 bits
        while (binaryForm.length() < 32) {
            binaryForm = '0' + binaryForm;
        }
        if (isNegative) binaryForm = '-' + binaryForm;
        return binaryForm;
    }
};