



// Time: O(N * N), where N is the size of the dimension of the grid
// Space: O(N * N)
class Solution 
{
    public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return {};
        int n = grid.size();
        int maxi = n * n;

        vector<int> counter(maxi+1, 0);

        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                counter[grid[r][c]]++;
            }
        }

        int rep = -1;
        int missing = -1;

        for (int i=0; i<maxi+1; i++) {
            if (counter[i] == 0) missing = i;
            if (counter[i] == 2) rep = i;
        }
        
        return {rep, missing};
    }
};