class Solution 
{
    public:
    // num1 = "011"
    // num2 = "123"
    string addStrings(string num1, string num2) 
    {
        if (num1.length() == 0 && num2.length() == 0) return "";
        if (num1.length() == 0) return num2;
        if (num1.length() == 0) return num1;

        int carry = 0;
        int i = num1.length()-1;
        int j = num2.length()-1;
        string res = "";

        while (i>=0 || j >=0 || carry) {
            int sum = carry;
            if (i>=0) {
                sum += num1[i] - '0'; // str to int
                i--;
            }
            if (j>=0) {
                sum += num2[j] - '0'; // str to int
                j--;
            }

            int digit = sum % 10;
            carry = sum / 10;
            res = to_string(digit) + res;
        }       
        return res;
    }
};