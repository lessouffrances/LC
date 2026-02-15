class Solution 
{
    public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return {};
        int n = grid.size();
        int maxi = n * n;

        unordered_set<int>numSet;
        for (int i=1; i<=maxi; i++) {
            numSet.insert(i);
        }

        vector<int> res(2);
        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                if (numSet.count(grid[r][c])) {
                    numSet.erase(grid[r][c]);
                } else {
                    res[0] = grid[r][c];
                }
            }
        }

        res[1] = *numSet.begin();
        return res;
    }
};