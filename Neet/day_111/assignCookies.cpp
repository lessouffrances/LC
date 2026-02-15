




// g = [1,2], s = [1,2,3], exp = 2
//  g = [2,1], s = [3,2,1]
//           j        i

// g = [1,2,3], s = [1,1], exp = 1
// g = [3,2,1], s = [1,1]
//          j        i
class Solution 
{
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        if (g.empty()) return 0;

        sort(g.begin(), g.end(), [](const auto& a, const auto& b){
            return a > b;
        });
        sort(s.begin(), s.end(), [](const auto& a, const auto& b){
            return a > b;
        });

        int numOfContentChildren = 0;
        int j = 0;
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (j >= g.size()) return numOfContentChildren;
            while (j < g.size() && s[i] < g[j]) {
                j++;
            }
            if (j < g.size() && s[i] >= g[j]) {
                numOfContentChildren++;
                j++;
            }
        }
        return numOfContentChildren;
    }
};