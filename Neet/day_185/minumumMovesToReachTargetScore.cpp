// T: O(TARGET-1)
// S: O(1)

class Solution 
{
    public:
    int minMoves(int target, int maxDoubles) 
    {
        if (maxDoubles == 0) return target-1;

        int moves = 0;
        while (target > 1 && maxDoubles > 0) {
            if (target % 2 == 0) {
                target /= 2;
                moves++;
                maxDoubles--;
            } else {
                target--;
                moves++;
            }
        }
        if (target > 1) moves += target-1;
        return moves;
    }
};