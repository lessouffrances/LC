class Solution 
{
    public:
    int findCelebrity(int n) 
    {
        if (n == 1) return -1;

        // first pass
        int candidate = 0;
        for (int i=1; i<n; i++) {
            // if this candidates knows someone, change to the next
            if (knows(candidate, i)) candidate = i;
        }

        // second pass
        for (int i=0; i<n; i++) {
            if (i != candidate && (!knows(i, candidate) || knows(candidate, i))) {
                return -1;
            }
        }
        return candidate;
    }
};