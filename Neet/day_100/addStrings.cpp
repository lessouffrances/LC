







// num1 = "456", 
// num2 = "77", output = "533"


// num1 = "1"
// num2 = "9"


class Solution 
{
    public:
    string addStrings(string num1, string num2) 
    {
        if (num1.length() == 0) return num2;
        if (num2.length() == 0) return num1;

        int i = num1.length()-1; 
        int j = num2.length()-1; 

        int carry = 0; //0
        string res = ""; 
        while (i >= 0 || j >= 0 || carry) { 
            int sum = carry; //0 1

            if (i >= 0) {
                sum += num1[i]-'0'; //1
                i--; 
            }
            if (j >= 0) {
                sum += num2[j]-'0'; //10
                j--; 
            }
            
            int val = sum % 10; //0 1
            carry = sum / 10; //1 0
            res += (val+'0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};