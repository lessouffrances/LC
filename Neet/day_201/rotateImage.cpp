class Solution 
{
    public:
    void rotate(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return;
        int n = matrix.size();

        for (int r=0; r<n; r++) {
            for (int c=r+1; c<n; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
        return;
    }
};