class Solution 
{
    public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return {};
        int n = grid.size();
        int maxi = n * n;

        vector<int>counter(maxi+1, 0);
        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                counter[grid[r][c]]++;
            }
        }

        int rep = -1;
        int miss = -1;
        for (int i=1; i<=maxi; i++) {
            if (counter[i] == 0) miss = i;
            if (counter[i] == 2) rep = i;
        }
        
        return {rep, miss};
    }
};