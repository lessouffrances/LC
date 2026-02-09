






class Solution 
{
    public:
    int maxDepth(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        int maxDepth = INT_MIN;

        int depth = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                depth++;
            } else if (s[i] == ')') {
                depth--;
            }
            maxDepth = max(maxDepth, depth);
        }
        return maxDepth;
    }
};