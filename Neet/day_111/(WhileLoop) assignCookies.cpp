class Solution 
{
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        if (g.empty()) return 0;

        int m = g.size(), n = s.size();
        int i = 0, j = 0;

        int numOfContentChildren = 0;
        while (i < m && j < n) {
            if (s[j] >= g[i]) {
                numOfContentChildren++;
                i++;
            }
            j++;
        }
        return numOfContentChildren;
    }
};
