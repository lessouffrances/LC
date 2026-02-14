class Solution 
{
    public:
    string addStrings(string num1, string num2) 
    {
        if (num1.length() == 0) return num2;
        if (num2.length() == 0) return num1;

        int i = num1.length()-1;
        int j = num2.length()-1;

        string res = "";
        int carry = 0;
        while (i>=0 || j>=0 || carry) {
            int sum = carry;

            if (i>=0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j>=0) {
                sum += num2[j] - '0';
                j--;
            }

            int digit = sum % 10;
            carry = sum / 10;
            res += (digit + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};