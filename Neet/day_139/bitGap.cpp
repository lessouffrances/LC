

// [1 0 1 1 0]
// Time: O(log N)
// Space: O(log N)
class Solution 
{
    public:
    int binaryGap(int n) 
    {
        string bin = decimalToBinary(n);
        int len = bin.length();

        int left = -1;
        int dist = 0;
        for (int right=0; right<len; right++) {
            if (bin[right] == '1') {
                if (left != -1) dist = max(dist, right-left);
                left = right;
            }
        }
        return dist;
    }
    private:
    string decimalToBinary(int n)
    {
        if (n == 0) return "0";
        string res;
        while (n > 0) {
            res += (char)('0' + n % 2);
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};