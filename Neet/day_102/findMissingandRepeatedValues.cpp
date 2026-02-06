








class Solution 
{
    public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return {};

        vector<int> res(2);
        int n = grid.size();

        unordered_set<int> numSet;
        for (int i=1; i<=n*n; i++) {
            numSet.insert(i);
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!numSet.count(grid[i][j])) {
                    res[0] = grid[i][j]; // repeated
                    continue;
                }
                numSet.erase(grid[i][j]);
            }
        }

        res[1] = *numSet.begin(); //missing
        return res;
    }
};