




class Solution 
{
    public:
    void rotate(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return;
        int n = matrix.size();

        // get the transpose of the matrix
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row
        for (int row=0; row<n; row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};