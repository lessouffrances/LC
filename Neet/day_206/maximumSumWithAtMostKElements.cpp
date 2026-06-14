class Solution 
{
    public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) 
    {
        // since for row i, the limit is limits[i]
        // why don't we just extract the top limits[i] elements from each row?
        int n = grid.size();
        vector<int> candidates;

        for (int i=0; i<n; i++) {
            sort(grid[i].rbegin(), grid[i].rend());
            int limit = limits[i];
            for (int j=0; j<limit; j++) {
                candidates.push_back(grid[i][j]);
            }
        }

        // take the top k
        sort(candidates.rbegin(), candidates.rend());
        long long res = 0;
        for (int i=0; i<k && i<candidates.size(); i++) {
            res += candidates[i];
        }
        return res;
    }
};