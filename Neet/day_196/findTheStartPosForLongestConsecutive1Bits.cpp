


// 5 => 101
//      1*2^0 + 0*2^1 + 1*2^2
// 
class Solution 
{
    public:
    pair<int, int> findTheStartPosForLongestConsecutive1Bits(int n) 
    {
        int bitPos = 0;
        int currCount = 0;
        int currStart = 0;
        int maxCount = 0;
        int startPos = 0;
        
        while (n != 0) {
            if (n % 2 != 0) {
                // bit is 1
                if (currCount == 0) currStart = bitPos;
                currCount++;
                if (currCount > maxCount) {
                    maxCount = currCount;
                    startPos = currStart;
                }
            } else {
                // bit is 0
                currCount = 0;
            }
            bitPos++;
            n /= 2;
        }
        return { maxCount, startPos };
    }
};