






class Solution 
{
    public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return {};
        int n = grid.size();

        unordered_set<int> numbers;
        for (int i=1; i<=n*n; i++) {
            numbers.insert(i);
        }

        vector<int> res(2);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!numbers.count(grid[i][j])) {
                    res[0] = grid[i][j];
                    continue;
                }
                numbers.erase(grid[i][j]);
            }
        }

        res[1] = *numbers.begin();
        return res;
    }
};