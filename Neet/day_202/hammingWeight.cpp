class Solution 
{
    public:
    int maxConsecutiveOnes(int n) 
    {
        int res = 0;
        int left = -1, right = 0;
        int maxLen = 0;
        pair<int, int> res;

        while (n) {
            right++;
            int digit = n % 2;
            n /= 2;

            if (digit == 1) {
                if (left == -1) left = right; // start a new run
                int currLen = right-left+1;
                if (currLen > maxLen) {
                    res.first = left;
                    res.second = right;
                    maxLen = currLen;
                }
                currLen = 0;
            } else {
                left = -1; // reset
            }
            
        }
        return res;
    }
};
