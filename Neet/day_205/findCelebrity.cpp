class Solution 
{
    public:
    int findCelebrity(int n) 
    {
        if (n == 1) return -1;

        // first pass: try to find a person who does not know anyone
        int candidate = 0;
        for (int i=0; i<n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }

        // second pass: verify this candidate does not know anyone
        for (int i=0; i<n; i++) {
            if (i != candidate && !(knows(i, candidate) && !knows(candidate, i))) {
                return -1;
            }
        }
        return candidate;
    }
};