






// "2 3"
// "4 5"
//    15    => [0,0,1,5]
//   12     => [0,1,3,5]
//   10     => [0,2,3,5]
//  8       => [1,0,3,5]
// 1035

// use 3*5 = 15 as an example, 
// i and j from right for two strings,
// the digit (%10) will land on the p1=i+j, 
// the base10 (/10) will land on the  p2= i+j+1 from the left of the output

class Solution 
{
    public:
    string multiply(string num1, string num2) 
    {
        int m = num1.size();
        int n = num2.size();

        vector<int> digits(m+n, 0); // the length of the result must be m+n
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                int multiply = (num1[i]-'0') * (num2[j]-'0');
                int p1 = i+j, p2 = i+j+1;
                int sum = multiply + digits[p2];
                digits[p2] = sum % 10;
                digits[p1] += sum / 10;
            }
        }

        string res;
        for (int d : digits) {
            if (!(res.empty() && d == 0)) { // only skip leading zeros
                res += to_string(d);
            }
        }
        return res.empty() ? "0" : res;
    }
};