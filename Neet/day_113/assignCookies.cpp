




// g = [1,2,3], s = [1,1]

class Solution 
{
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        if (g.empty()) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = g.size()-1;
        int j = s.size()-1;

        int numOfContentChildren = 0;
        while (i>=0 && j>=0) {
            if (s[j] >= g[i]) {
                j--;
                numOfContentChildren++;
            }
            i--; // child must move
        }
        return numOfContentChildren;
    }
};