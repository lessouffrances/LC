


// 5 => 101
//      1*2^0 + 0*2^1 + 1*2^2
// 
class Solution 
{
    public:
    int hammingWeight(int n) 
    {
        int res = 0;
        while (n) {
            res += (n % 2);
            n /= 2;
        }
        return res;
    }
};