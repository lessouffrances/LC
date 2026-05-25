class Solution 
{
    public:
    int furthestDistanceFromOrigin(string moves) 
    {
        if (moves.length() == 0) return 0;

        int currDist = 0;
        vector<int> freq(2, 0);
        int countOfSpace = 0;
        for (char ch : moves) {
            if (ch != 'L' && ch != 'R') {
                countOfSpace++;
                continue;
            }

            if (ch == 'L') {
                freq[0]++;
                currDist -= 1;
            } else if (ch == 'R') {
                freq[1]++;
                currDist += 1;
            } 

        }

        if (freq[0] > freq[1]) {
            // L dominates
            return abs(currDist - countOfSpace);
        } 
        return abs(currDist + countOfSpace);
    }
};